#ifndef BASIC
#define BASIC

#include <string>
#include <vector>

#include "Token.hpp"

namespace Basic
{
    void PrintRedText(const char *a_text);
    std::vector<Token> Run(const std::string &a_file_name, const std::string &a_text);
} // namespace Basic

#endif /* BASIC */