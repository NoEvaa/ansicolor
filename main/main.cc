#include "ansi_color.hpp"
#include <iostream>

int main()
{
    using namespace ansi_color;

    std::cout << "hello";
    std::cout << AnsiColor(ColorSpec::kRed) << " world" << std::endl;
    std::cout << "hello" << AnsiColor(ColorSpec::kReset) << " world" << std::endl;
    std::cout << AnsiColor({102, 204, 255}) << "hello"
        << AnsiColor(ColorSpec::kWhite, ColorTarget::kBackground) << " world" << std::endl;
    std::cout << AnsiColor(ColorSpec::kDefault) << "hello"
        << AnsiColor(ColorSpec::kReset) << " world" << std::endl;
    std::cout << "hello world" << std::endl;

    return 0;
}

