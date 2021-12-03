#ifndef TOKEN
#define TOKEN

#include <string>

#include "TT.hpp"

namespace Basic
{
    class Token
    {
    public:
        Token(TT a_type, std::string a_value = "");
        ~Token() {}

        int GetTypeInt();
        TT GetType() { return m_type; }
        void PrintType();

        std::string GetValue() { return m_value; }

    private:
        std::string m_value;
        TT m_type;
    };
}
#endif /* TOKEN */