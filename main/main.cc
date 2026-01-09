#include "ansi_color.hpp"
#include <iostream>
#include <sstream>

int main()
{
    using namespace ansi_color;

    std::cout << "1 hello";
    std::cout << AnsiColor(ColorSpec::kRed) << " world" << std::endl;

    std::cout << AnsiColor(ColorSpec::kNone) << "hi world" << std::endl;
    
    std::stringstream ss;
    ss << "2 hello" << AnsiColor(ColorSpec::kReset) << " world" << std::endl;
    std::cout << ss.str();

    constexpr auto kTianyiBlue = AnsiColor({102, 204, 255});
    auto           white_bg    = AnsiColor(ColorSpec::kWhite, ColorTarget::kBg);
    std::cout
        << kTianyiBlue << "3 hello"
        << white_bg << " world"
        << std::endl;

    std::cout
        << AnsiColor(ColorSpec::kDefault) << "4 hello"
        << AnsiColor(ColorSpec::kReset) << " world"
        << std::endl;

    std::cout << "5 hello world" << std::endl;

#define COUT_COLOR(_color) \
    std::cout << AnsiColor(ColorSpec::k##_color) << #_color << std::endl
    
    COUT_COLOR(Black);
    COUT_COLOR(Red);
    COUT_COLOR(Green);
    COUT_COLOR(Brown);
    COUT_COLOR(Blue);
    COUT_COLOR(Magenta);
    COUT_COLOR(Cyan);
    COUT_COLOR(White);
    COUT_COLOR(Default);

#undef COUT_COLOR

	std::uintptr_t address = 0x123456789;
	std::cout << "Address "
        << std::showbase << std::hex << AnsiColor{ColorSpec::kBlue}
        << address << std::endl;

    std::cout << "number: " << std::dec << std::showpos << AnsiColor{ColorSpec::kRed} << 123 << std::endl;

    return 0;
}

