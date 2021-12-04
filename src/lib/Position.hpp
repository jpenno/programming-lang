#ifndef POSITION
#define POSITION

#include <vector>
#include <string>

namespace Basic
{
    class Position
    {
    public:
        Position(int a_idx, int a_ln, int a_col, std::string a_fileName, std::string a_fileText);

        void Advance(char a_current_character);
        inline int GetIdx() { return m_idx; }
        inline int GetLn() { return m_ln; }
        inline int GetCol() { return m_col; }
        inline std::string GetFileName() { return m_fileName; }

    private:
        int m_idx;
        int m_ln;
        int m_col;
        std::string m_fileName;
        std::string m_fileText;
    };
} // namespace Basic
#endif /* POSITION */