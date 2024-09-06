# ANSI Color

[中文](README_CN.md)

`ansicolor` is a minimal, header-only, single-file modern C++ library for 
colorful terminal output with console code.

## Application

- Output colored text in the console.

- All terminals that support ANSI color standards.

## Features

- Lightweight: Only one header file with one hundred lines of code.

- Convenient: Only one structure and two enum classes need to be used.

## Quick Start

### Building

```bash
sh build.sh
./build/bin/debug/ansicolor_main
```

### Usage

#### Include header

```cpp
#include <ansi_color.hpp>

using ansi_color::AnsiColor;
using ansi_color::ColorSpec;
using ansi_color::ColorTarget;

```

#### Define color

```cpp
// reset
AnsiColor();
// default color
AnsiColor(ColorSpec::kDefault);
// built-in color
AnsiColor(ColorSpec::kRed);
// RGB color
AnsiColor({102, 204, 255});
// background color
AnsiColor(ColorSpec::kWhite, ColorTarget::kBackground);

```

| **ColorSpec** | **Description** |
|---------------|-----------------|
| **kNone**     | Do nothing      |
| **kReset**    | Reset           |
| **kDefault**  | Default color   |
| **kRgb**      | RGB color       |
| **kBlack**    | Black           |
| **kRed**      | Red             |
| **kGreen**    | Green           |
| **kBrown**    | Brown           |
| **kBlue**     | Blue            |
| **kMagenta**  | Magenta         |
| **kCyan**     | Cyan            |
| **kWhite**    | White           |

| **ColorTarget**      | **Description**  |
|----------------------|------------------|
| **kForeground(kFg)** | Foreground color |
| **kBackground(kBg)** | Background color |

#### Output stream

```cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Output red font and return to default font color.

constexpr auto default_fg = AnsiColor(ColorSpec::kDefault);

std::stringstream ss;
ss << AnsiColor(ColorSpec::kRed) << "red" << default_fg;

std::cout << ss.str() << std::endl;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Output gray background and reset console code.

auto gray_bg = AnsiColor({127, 127, 127}, ColorTarget::kBg);
std::cout << gray_bg << "gray background" << AnsiColor() << std::endl;

```

## Authors

- [@NoEvaa](https://github.com/NoEvaa)

## License

[MIT](LICENSE)

