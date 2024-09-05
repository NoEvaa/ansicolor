/**
 * MIT License
 *
 * Copyright (c) 2024 NoEvaa
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef AYIN_ANSI_COLOR_HPP_
#define AYIN_ANSI_COLOR_HPP_

#include <cstdint>
namespace ansi_color {

enum class ColorSpec {
    kReset = 0,
    kDefault,
    kRgb,

    kBlack = 10,
    kRed,
    kGreen,
    kBrown,
    kBlue,
    kMagenta,
    kCyan,
    kWhite,
};

enum class ColorTarget {
    kForeground = 0,
    kBackground,
};

namespace detail {

struct RgbColor {
    std::uint8_t red_   = 0;
    std::uint8_t green_ = 0;
    std::uint8_t blue_  = 0;

    constexpr RgbColor() = default;
    constexpr RgbColor(int _r, int _g, int _b)
        : red_(_r & 0xff), green_(_g & 0xff), blue_(_b & 0xff) {}
};

struct Color {
    ColorSpec spec_ = ColorSpec::kReset;
    RgbColor  rgb_;

    constexpr Color() = default;
    constexpr Color(ColorSpec _spec) : spec_(_spec) {}
    constexpr Color(int _r, int _g, int _b)
        : spec_(ColorSpec::kRgb), rgb_(_r, _g, _b) {}
};

} // ansi_color::detail

} // ansi_color

#endif
