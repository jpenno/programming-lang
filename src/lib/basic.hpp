#ifndef BASIC
#define BASIC

#include <iostream>
#include <string.h>
#include <vector>
#include <tuple>

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

    class Error
    {
    public:
        Error(string a_name, string a_details)
        {
            m_name = a_name;
            m_details = a_details;
        }

        string AsString();
        void Print();

    private:
        string m_name;
        string m_details;
    };

    class Token
    {
    public:
        Token(TT a_type, string a_value);
        ~Token() {}

        int GetTypeInt();
        TT GetType() { return m_type; }
        void PrintType();

        string GetValue() { return m_value; }

    private:
        string m_value;
        TT m_type;
    };

    class Lexer
    {
    public:
        Lexer(string a_text);

        std::tuple<vector<Token>, vector<Error>> MakeTokens();
        void Advance();
        bool InRange();
        char GetCurrentChar();

    private:
        string m_text;
        string m_fileName;
        u_int32_t m_pos;
        char m_currentChar;

        Token MakeNumber();
    };

    void PrintRedText(const char *a_text);
    vector<Token> Run(const string &text);
} // namespace Basic

#endif /* BASIC */