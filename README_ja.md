# Xiaozhi Avatar Face

（日本語 | [中文](README.md) | [English](README_en.md)）

## 紹介

本プロジェクトは、オープンソースの ESP32 小智音声アシスタントを基にした二次開発です。ハードウェアには M5Stack AtomS3R と Atomic Echo Base を使用し、独自の筐体設計を組み合わせ、表情表示は M5Stack Avatar Face に変更されています。

![pic_01](./docs/pic_01.jpg)
![pic_02](./docs/pic_02.jpg)
![pic_03](./docs/pic_03.jpg)

## ハードウェア

- [AtomS3R](https://docs.m5stack.com/en/products/sku/C126)
- [Atomic Echo Base](https://docs.m5stack.com/en/products/sku/A149)

## ソフトウェア

- ESP-IDF: v5.4.2

```bash
git clone --recursive https://github.com/Gitshaoxiang/xiaozhi-esp32-avatar.git
cd xiaozhi-esp32-avatar
. $IDF_PATH/export.sh
idf.py menuconfig # Config Wake Words：ESP Speech Recognition ->  Load Multiple Wake Words 
idf.py build
```

## よくある質問

以下のエラーが表示された場合は、ビルドキャッシュ（build）と依存パッケージ（managed_components）を削除し、`idf.py build` を再実行してください。

```bash
fatal error: assets/lang_config.h: No such file or directory
```

## 関連プロジェクト

- [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32)
- [m5stack-avatar](https://github.com/stack-chan/m5stack-avatar)
- [M5Unified](https://github.com/m5stack/M5Unified)
- [M5GFX](https://github.com/m5stack/M5GFX)
