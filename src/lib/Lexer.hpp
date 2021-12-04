#ifndef LEXER
#define LEXER

#include <string>
#include <vector>
#include <tuple>

#include "Token.hpp"
#include "Position.hpp"
#include "Error.hpp"

namespace Basic
{
    class Lexer
    {
    public:
        Lexer(std::string a_file_name, std::string a_text);

        std::tuple<std::vector<Token>, std::vector<Error>> MakeTokens();
        void Advance();
        char GetCurrentChar();

    private:
        std::string m_text;
        std::string m_fileName;
        Position m_pos;
        char m_currentChar;

        Token MakeNumber();
    };
} // namespace Basic
#endif /* LEXER */