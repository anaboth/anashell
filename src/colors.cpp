#include "../include/colors.hpp"

std::string fg(int color){
    std::string s;
    s = "\033[0;"; 
    s += std::to_string(color + 30);
    s += "m";
    return s;
}

std::string bg(int color){
    std::string s;
    s = "\033[0;"; 
    s += std::to_string(color + 40);
    s += "m";
    return s;
}

std::string reset_prompt() { return "\033[0m"; }
