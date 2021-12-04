#include "Basic.hpp"
#include <iostream>
#include <ctype.h>

#include "Lexer.hpp"
#include "Error.hpp"


using std::string;
using std::vector;

using namespace Basic;

vector<Token> Basic::Run(const string &a_file_name, const string &a_text)
{
    Lexer lexer = Lexer(a_file_name, a_text);
    auto [tokens, errors] = lexer.MakeTokens();

    if (!errors.empty())
    {
        for (auto &&error : errors)
        {
            error.Print();
        }
    }
    return tokens;
}

void Basic::PrintRedText(const char *a_text)
{
    printf("\x1B[31m%s\033[0m", a_text);
}
