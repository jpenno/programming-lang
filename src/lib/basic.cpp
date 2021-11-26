#include "basic.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace Basic;

vector<Token> Basic::Run(const string &text)
{
    Lexer lexer = Lexer(text);
    vector<Token> tokens = lexer.MakeTokens();
    return tokens;
}

Basic::Token::Token(TT a_type, string a_value = "")
{
    m_type = a_type;
    m_value = a_value;
}

int Token::GetTypeInt()
{
    return static_cast<int>(m_type);
}

void Token::PrintType()
{
    switch (m_type)
    {
    case TT::PLUS:
        cout << "[ PLUS ]";
        break;
    case TT::MINUS:
        cout << "[ MINUS ]";
        break;
    case TT::MUL:
        cout << "[ MUL ]";
        break;
    case TT::DIV:
        cout << "[ DIV ]";
        break;
    case TT::LPAREN:
        cout << "[ LPAREN ]";
        break;
    case TT::RPAREN:
        cout << "[ RPAREN ]";
        break;
    default:
        cout << "[ TYPE NOT SET ]";
        break;
    }
}
Basic::Lexer::Lexer(string a_text)
{
    m_text = a_text;
    m_pos = 0;
    m_currentChar = m_text[0];
}

void Basic::Lexer::Advance()
{
    m_pos += 1;
    if (m_pos < m_text.length())
    {
        m_currentChar = m_text[m_pos];
    }
}
bool Basic::Lexer::InRange()
{
    if (m_pos < m_text.length())
    {
        return true;
    }
    return false;
}

char Basic::Lexer::GetCurrentChar()
{
    return m_currentChar;
}

vector<Token> Basic::Lexer::MakeTokens()
{
    vector<Token> tokens = vector<Token>();

    while (InRange())
    {
        if (GetCurrentChar() == '*')
        {
            tokens.push_back(Token(TT::MUL));
            Advance();
        }
        else if (GetCurrentChar() == '+')
        {
            tokens.push_back(TT::PLUS);
            Advance();
        }
        else if (GetCurrentChar() == '-')
        {
            tokens.push_back(TT::MINUS);
            Advance();
        }
        else if (GetCurrentChar() == '/')
        {
            tokens.push_back(TT::DIV);
            Advance();
        }
        else if (GetCurrentChar() == '(')
        {
            tokens.push_back(TT::LPAREN);
            Advance();
        }
        else if (GetCurrentChar() == ')')
        {
            tokens.push_back(TT::RPAREN);
            Advance();
        }
        else
        {
            cout << "Not Handled" << endl;
            Advance();
        }
    }
    return tokens;
}