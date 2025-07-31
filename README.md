# Xiaozhi Avatar Face

（中文 | [English](README_en.md) | [日本語](README_ja.md)）

## 介绍

本项目基于虾哥开源的 ESP32 小智语音助手进行二次开发。硬件使用 M5Stack AtomS3R + Atomic Echo Base 搭配结构设计，修改显示表情包为 M5Stack Avatar Face。

![pic_01](./docs/pic_01.jpg)
![pic_02](./docs/pic_02.jpg)
![pic_03](./docs/pic_03.jpg)

## 硬件

- [AtomS3R](https://docs.m5stack.com/en/products/sku/C126)
- [Atomic Echo Base](https://docs.m5stack.com/en/products/sku/A149)

## 软件

- ESP-IDF: v5.4.2

```bash
git clone --recursive https://github.com/Gitshaoxiang/xiaozhi-esp32-avatar.git
cd xiaozhi-esp32-avatar
. $IDF_PATH/export.sh
idf.py menuconfig # Config Wake Words：ESP Speech Recognition ->  Load Multiple Wake Words 
idf.py build
```

## 常见问题

如果编译过程中出现以下报错，请删除编译缓存(build)与依赖包(managed_components)重新执行`idf.py build`编译。

```bash
fatal error: assets/lang_config.h: No such file or directory
```

## 相关开源项目

- [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32)
- [m5stack-avatar](https://github.com/stack-chan/m5stack-avatar)
- [M5Unified](https://github.com/m5stack/M5Unified)
- [M5GFX](https://github.com/m5stack/M5GFX)
