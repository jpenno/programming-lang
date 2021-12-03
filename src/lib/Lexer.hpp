#ifndef LEXER
#define LEXER

#include <vector>
#include <tuple>

#include "Token.hpp"
#include "Error.hpp"

namespace Basic
{
    class Lexer
    {
    public:
        Lexer(std::string a_text);

        std::tuple<std::vector<Token>, std::vector<Error>> MakeTokens();
        void Advance();
        bool InRange();
        char GetCurrentChar();

    private:
        std::string m_text;
        std::string m_fileName;
        u_int32_t m_pos;
        char m_currentChar;

        Token MakeNumber();
    };
} // namespace Basic
#endif /* LEXER */