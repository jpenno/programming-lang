#include "Lexer.hpp"

using std::string;
using std::vector;

using namespace Basic;

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

std::tuple<vector<Token>, vector<Error>> Basic::Lexer::MakeTokens()
{
    vector<Token> tokens = vector<Token>();
    vector<Error> errors = vector<Error>();

    while (InRange())
    {
        if (isspace(m_currentChar))
        {
            Advance();
        }
        else if (isdigit(m_currentChar))
        {
            tokens.push_back(MakeNumber());
        }
        else if (m_currentChar == '*')
        {
            tokens.push_back(Token(TT::MUL));
            Advance();
        }
        else if (m_currentChar == '+')
        {
            tokens.push_back(TT::PLUS);
            Advance();
        }
        else if (m_currentChar == '-')
        {
            tokens.push_back(TT::MINUS);
            Advance();
        }
        else if (m_currentChar == '/')
        {
            tokens.push_back(TT::DIV);
            Advance();
        }
        else if (m_currentChar == '(')
        {
            tokens.push_back(TT::LPAREN);
            Advance();
        }
        else if (m_currentChar == ')')
        {
            tokens.push_back(TT::RPAREN);
            Advance();
        }
        else
        {
            string details = "'";
            details += m_currentChar;
            details += "'";
            errors.push_back(Error("Illegal Character", details));
            return {tokens, errors};
        }
    }
    return {tokens, errors};
}

Token Basic::Lexer::MakeNumber()
{
    string numStr = "";
    int dotCount = 0;

    while (InRange() && (isdigit(m_currentChar) || m_currentChar == '.'))
    {
        if (m_currentChar == '.')
        {
            if (dotCount == 1)
            {
                break;
            }

            dotCount += 1;
            numStr += '.';
        }
        else
        {
            numStr += m_currentChar;
        }
        Advance();
    }

    if (dotCount == 0)
    {
        return Token(TT::INT, numStr);
    }
    else
    {
        return Token(TT::FLOAT, numStr);
    }
}