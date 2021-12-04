#ifndef ERROR
#define ERROR

#include <vector>
#include <tuple>
#include <string>

#include "Position.hpp"

namespace Basic
{
    class Error
    {
    public:
        Error(std::string a_name, std::string a_details, Position a_pos);

        std::string AsString();
        void Print();

    private:
        std::string m_name;
        std::string m_details;
        Position m_pos;
    };
} // namespace Basic
#endif /* ERROR */