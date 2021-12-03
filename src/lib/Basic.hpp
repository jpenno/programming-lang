#ifndef BASIC
#define BASIC

#include <string>
#include <vector>

#include "Token.hpp"

namespace Basic
{
    void PrintRedText(const char *a_text);
    std::vector<Token> Run(const std::string &text);
} // namespace Basic

#endif /* BASIC */