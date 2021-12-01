#include "Token.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace Basic;

Token::Token(TT a_type, string a_value)
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
    case TT::INT:
        cout << "[ INT: " << m_value << " ]";
        break;
    case TT::FLOAT:
        cout << "[ FLOAT: " << m_value << " ]";
        break;
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