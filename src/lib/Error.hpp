#ifndef ERROR
#define ERROR

#include <vector>
#include <tuple>
#include <string>

namespace Basic
{
    class Error
    {
    public:
        Error(std::string a_name, std::string a_details)
        {
            m_name = a_name;
            m_details = a_details;
        }

        std::string AsString();
        void Print();

    private:
        std::string m_name;
        std::string m_details;
    };
} // namespace Basic
#endif /* ERROR */