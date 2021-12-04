#include "Position.hpp"

using namespace Basic;

Position::Position(int a_idx, int a_ln, int a_col, std::string a_fileName, std::string a_fileText)
{
    m_idx = a_idx;
    m_ln = a_ln;
    m_col = a_col;
    m_fileName = a_fileName;
    m_fileText = a_fileText;
}

void Position::Advance(char a_current_character)
{
    m_idx++;
    m_col++;

    if (a_current_character == '\n')
    {
        m_ln++;
        m_col = 0;
    }
}