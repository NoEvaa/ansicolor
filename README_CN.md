# ANSI Color

[English](README.md)

`ansicolor`是一个极小的、仅有一个头文件的C++库，它能用以在支持`console code`的终端上实现彩色输出。

## 适用场景

- 控制台输出彩色文本

- 支持ANSI颜色标准的终端

## 特色

- 轻量级：仅有一个百行头文件

- 简单便捷：仅需使用一个结构体以及两个枚举类

## 快速开始

### 构建

```bash
sh build.sh
./build/bin/debug/ansicolor_main
```

### 使用

#### 引入头文件

```cpp
#include <ansi_color.hpp>

using ansi_color::AnsiColor;
using ansi_color::ColorSpec;
using ansi_color::ColorTarget;

```

#### 定义颜色

```cpp
// 重置
AnsiColor();
// 默认颜色
AnsiColor(ColorSpec::kDefault);
// 内置颜色
AnsiColor(ColorSpec::kRed);
// RGB 颜色
AnsiColor({102, 204, 255});
// 背景色
AnsiColor(ColorSpec::kWhite, ColorTarget::kBackground);

```

| **ColorSpec** | **描述**   |
|---------------|------------|
| **kNone**     | 无所作为   |
| **kReset**    | 重置       |
| **kDefault**  | 默认颜色   |
| **kRgb**      | RGB颜色    |
| **kBlack**    | Black      |
| **kRed**      | Red        |
| **kGreen**    | Green      |
| **kBrown**    | Brown      |
| **kBlue**     | Blue       |
| **kMagenta**  | Magenta    |
| **kCyan**     | Cyan       |
| **kWhite**    | White      |

| **ColorTarget**      | **描述**   |
|----------------------|------------|
| **kForeground(kFg)** | 前景色     |
| **kBackground(kBg)** | 背景色     |

#### 输出流

```cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 输出红色字体后再恢复默认字体颜色

constexpr auto default_fg = AnsiColor(ColorSpec::kDefault);

std::stringstream ss;
ss << AnsiColor(ColorSpec::kRed) << "red" << default_fg;

std::cout << ss.str() << std::endl;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 输出灰色背景后再重置

auto gray_bg = AnsiColor({127, 127, 127}, ColorTarget::kBg);
std::cout << gray_bg << "gray background" << AnsiColor() << std::endl;

```

## 作者

- [@NoEvaa](https://github.com/NoEvaa)

## 许可证

[MIT](LICENSE)

