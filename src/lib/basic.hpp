#ifndef BASIC
#define BASIC

#include <iostream>
#include <string.h>
#include <vector>

using std::string;
using std::vector;

namespace Basic
{
    enum class TT
    {
        INT,
        FLOAT,
        PLUS,
        MINUS,
        MUL,
        DIV,
        LPAREN,
        RPAREN
    };

    class Token
    {
    private:
        string m_value;
        TT m_type;

    public:
        Token(TT a_type, string a_value);
        ~Token() {}

        int GetTypeInt();
        TT GetType() { return m_type; }
        void PrintType();
    };

    class Lexer
    {
    private:
        string m_text;
        string m_fileName;
        u_int32_t m_pos;
        char m_currentChar;

    public:
        Lexer(string a_text);

        vector<Token> MakeTokens();
        void Advance();
        bool InRange();
        char GetCurrentChar();
    };

    vector<Token> Run(const string &text);
} // namespace Basic

#endif /* BASIC */