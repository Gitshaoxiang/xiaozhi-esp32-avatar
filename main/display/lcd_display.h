#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include "display.h"

#include <esp_lcd_panel_io.h>
#include <esp_lcd_panel_ops.h>
#include <font_emoji.h>

#include <atomic>

#include <Avatar.h>
#include "M5Unified.h"
#include "M5GFX.h"
#include "faces/custom_faces.hpp"

using namespace m5avatar;

// Theme color structure
struct ThemeColors {
    lv_color_t background;
    lv_color_t text;
    lv_color_t chat_background;
    lv_color_t user_bubble;
    lv_color_t assistant_bubble;
    lv_color_t system_bubble;
    lv_color_t system_text;
    lv_color_t border;
    lv_color_t low_battery;
};

class LcdDisplay : public Display {
   protected:
    esp_lcd_panel_io_handle_t panel_io_ = nullptr;
    esp_lcd_panel_handle_t panel_       = nullptr;

    lv_draw_buf_t draw_buf_;
    lv_obj_t* status_bar_    = nullptr;
    lv_obj_t* content_       = nullptr;
    lv_obj_t* container_     = nullptr;
    lv_obj_t* side_bar_      = nullptr;
    lv_obj_t* preview_image_ = nullptr;

    DisplayFonts fonts_;
    ThemeColors current_theme_;

    void SetupUI();
    virtual bool Lock(int timeout_ms = 0) override;
    virtual void Unlock() override;

   protected:
    // 添加protected构造函数
    LcdDisplay(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_handle_t panel,
               DisplayFonts fonts, int width, int height);

   public:
    ~LcdDisplay();
    virtual void SetEmotion(const char* emotion) override;
    virtual void SetIcon(const char* icon) override;
    virtual void SetPreviewImage(const lv_img_dsc_t* img_dsc) override;
#if CONFIG_USE_WECHAT_MESSAGE_STYLE
    virtual void SetChatMessage(const char* role, const char* content) override;
#endif

    // Add theme switching function
    virtual void SetTheme(const std::string& theme_name) override;
};

// RGB LCD显示器
class RgbLcdDisplay : public LcdDisplay {
   public:
    RgbLcdDisplay(esp_lcd_panel_io_handle_t panel_io,
                  esp_lcd_panel_handle_t panel, int width, int height,
                  int offset_x, int offset_y, bool mirror_x, bool mirror_y,
                  bool swap_xy, DisplayFonts fonts);
};

// MIPI LCD显示器
class MipiLcdDisplay : public LcdDisplay {
   public:
    MipiLcdDisplay(esp_lcd_panel_io_handle_t panel_io,
                   esp_lcd_panel_handle_t panel, int width, int height,
                   int offset_x, int offset_y, bool mirror_x, bool mirror_y,
                   bool swap_xy, DisplayFonts fonts);
};

// // SPI LCD显示器
class SpiLcdDisplay : public LcdDisplay {
   public:
    SpiLcdDisplay(esp_lcd_panel_io_handle_t panel_io,
                  esp_lcd_panel_handle_t panel, int width, int height,
                  int offset_x, int offset_y, bool mirror_x, bool mirror_y,
                  bool swap_xy, DisplayFonts fonts);
};

// // avatar
class avatarDisplay : public Display {
   protected:
    virtual bool Lock(int timeout_ms = 0) override {
        return true;
    }

    virtual void Unlock() override {
        return;
    }

   public:
    struct Emotion {
        m5avatar::Expression avatar_emotion;
        char* text;
    };

    struct EmotionFace {
        m5avatar::Face* face;
        char* text;
    };

    std::vector<Emotion> _emotions;
    std::vector<EmotionFace> _faces;

    Avatar* _avatar          = nullptr;
    SleepFace sleep_face     = SleepFace();
    NervousFace nervous_face = NervousFace();
    LoveFace love_face       = LoveFace();
    CoolFace cool_face       = CoolFace();
    NeutraFace neutral_face  = NeutraFace();
    StarFace star_face       = StarFace();

    avatarDisplay(Avatar* avatar) : _avatar(avatar) {
        avatar->init();  // start drawingx
        adjust_position();
        _emotions = {{m5avatar::Expression::Neutral, "neutral"},
                     {m5avatar::Expression::Happy, "happy"},
                     {m5avatar::Expression::Sad, "sad"},
                     {m5avatar::Expression::Angry, "angry"},
                     {m5avatar::Expression::Sleeping, "sleeping"},
                     {m5avatar::Expression::Doubt, "confused"}};
    }

    void adjust_position() {
        // adjust position
        const auto r       = _avatar->getFace()->getBoundingRect();
        const auto scale_w = M5.Display.width() / (float)r->getWidth();
        const auto scale_h = M5.Display.height() / (float)r->getHeight();
        const auto scale   = std::min(scale_w, scale_h);
        _avatar->setScale(scale);
        const auto offs_x = (r->getWidth() - M5.Display.width()) / 2;
        const auto offs_y = (r->getHeight() - M5.Display.height()) / 2;
        _avatar->setPosition(-offs_y, -offs_x);
    }
    virtual ~avatarDisplay() {
        for (auto& face_pair : _faces) {
            delete face_pair.face;
        }
        _faces.clear();
    }

    virtual void SetEmotion(const char* emotion) override {
        std::string_view emotion_view(emotion);
        for (const auto& e : _emotions) {
            if (e.text == emotion_view) {
                _avatar->setExpression(e.avatar_emotion);
                break;
            }
        }

        if (emotion_view == "loving") {
            _avatar->setFace(&love_face);
        } else if (emotion_view == "sad" || emotion_view == "crying") {
            _avatar->setFace(&nervous_face);
        } else if (emotion_view == "funny" || emotion_view == "cool"|| emotion_view == "laughing") {
            _avatar->setFace(&cool_face);
        } else if (emotion_view == "kissy" || emotion_view == "winking") {
            _avatar->setFace(&star_face);
        } else if (emotion_view == "sleeping") {
            _avatar->setFace(&sleep_face);
        } else {
            _avatar->setFace(&neutral_face);
        }
        adjust_position();
        return;
    }
    virtual void SetIcon(const char* icon) override {
        return;
    }
    virtual void SetPreviewImage(const lv_img_dsc_t* img_dsc) override {
        return;
    }
    virtual void SetChatMessage(const char* role,
                                const char* content) override {
        // _avatar->setSpeechText(content);
        return;
    }

    // Add theme switching function
    virtual void SetTheme(const std::string& theme_name) override {
        return;
    }
};

// QSPI LCD显示器
class QspiLcdDisplay : public LcdDisplay {
   public:
    QspiLcdDisplay(esp_lcd_panel_io_handle_t panel_io,
                   esp_lcd_panel_handle_t panel, int width, int height,
                   int offset_x, int offset_y, bool mirror_x, bool mirror_y,
                   bool swap_xy, DisplayFonts fonts);
};

// MCU8080 LCD显示器
class Mcu8080LcdDisplay : public LcdDisplay {
   public:
    Mcu8080LcdDisplay(esp_lcd_panel_io_handle_t panel_io,
                      esp_lcd_panel_handle_t panel, int width, int height,
                      int offset_x, int offset_y, bool mirror_x, bool mirror_y,
                      bool swap_xy, DisplayFonts fonts);
};
#endif  // LCD_DISPLAY_H
