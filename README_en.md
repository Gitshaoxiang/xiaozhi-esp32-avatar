# Xiaozhi Avatar Face

(English | [中文](README.md) | [日本語](README_ja.md))

## Introduction

This project is a secondary development based on the open-source ESP32 Xiaozhi voice assistant. It uses M5Stack AtomS3R and Atomic Echo Base with a custom structural design, and replaces the expression display with M5Stack Avatar Face.

![pic_01](./docs/pic_01.jpg)
![pic_02](./docs/pic_02.jpg)
![pic_03](./docs/pic_03.jpg)

## Hardware

- [AtomS3R](https://docs.m5stack.com/en/products/sku/C126)
- [Atomic Echo Base](https://docs.m5stack.com/en/products/sku/A149)

## Software

- ESP-IDF: v5.4.2

```bash
git clone --recursive https://github.com/Gitshaoxiang/xiaozhi-esp32-avatar.git
cd xiaozhi-esp32-avatar
. $IDF_PATH/export.sh
idf.py menuconfig # Config Wake Words：ESP Speech Recognition ->  Load Multiple Wake Words 
idf.py build
```

## FAQ

if the following error occurs during compilation, please delete the build cache (build) and dependencies (managed_components), then run `idf.py build` again.

```bash
fatal error: assets/lang_config.h: No such file or directory
```

## Related Projects

- [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32)
- [m5stack-avatar](https://github.com/stack-chan/m5stack-avatar)
- [M5Unified](https://github.com/m5stack/M5Unified)
- [M5GFX](https://github.com/m5stack/M5GFX)

