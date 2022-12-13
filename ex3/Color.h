#ifndef CLASS_COLOR_H
#define CLASS_COLOR_H


#include <iostream>

using namespace std;

namespace Color {
    enum Code {
        FB_BLACK          = 30,
        FG_RED            = 31,
        FG_GREEN          = 32,
        FB_YELLOW         = 33,
        FG_BLUE           = 34,
        FB_MAGENTA        = 35,
        FB_CYAN           = 36,
        FG_WHITE          = 37,
        FG_DEFAULT        = 39,
        FB_BRIGHT_BLACK   = 90,
        FB_BRIGHT_RED     = 91,
        FB_BRIGHT_GREEN   = 92,
        FB_BRIGHT_YELLOW  = 93,
        FB_BRIGHT_BLUE    = 94,
        FB_BRIGHT_MAGENTA = 95,
        FB_BRIGHT_CYAN    = 96,
        FB_BRIGHT_WHITE   = 97,
        BG_BLACK          = 40,
        BG_RED            = 41,
        BG_GREEN          = 42,
        BG_YELLOW         = 43,
        BG_BLUE           = 44,
        BG_MAGENTA        = 45,
        BG_CYAN           = 46,
        BG_WHITE          = 47,
        BG_DEFAULT        = 49,
        BG_BRIGHT_BLACK   = 100,
        BG_BRIGHT_RED     = 101,
        BG_BRIGHT_GREEN   = 102,
        BG_BRIGHT_YELLOW  = 103,
        BG_BRIGHT_BLUE    = 104,
        BG_BRIGHT_MAGENTA = 105,
        BG_BRIGHT_CYAN    = 106,
        BG_BRIGHT_WHITE   = 107,
        BOLD              = 1,
        UNDERLINE         = 4,
        BLINK             = 5,
        REVERSE           = 7,
        CONCEALED         = 8,
        RESET             = 0,
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}


#endif //CLASS_COLOR_H