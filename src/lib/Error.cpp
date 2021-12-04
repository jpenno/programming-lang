#include "Error.hpp"
#include <iostream>

#include "Basic.hpp"

using std::cout;
using std::endl;
using std::string;

using namespace Basic;

Error::Error(std::string a_name, std::string a_details, Position a_pos)
    : m_pos(a_pos),
      m_details(a_details),
      m_name(a_name)
{
}
string Error::AsString()
{
    string result = "";
    result += m_name;
    result += ": ";
    result += m_details;

    return result;
}

void Error::Print()
{
    PrintRedText(m_name.c_str());
    cout << endl;
    cout << '\t' << "FN: " << m_pos.GetFileName() << " -> "
         << "LN: " << m_pos.GetLn();
    cout << " -> "
         << "COL: " << m_pos.GetCol() << endl;
    cout << '\t' << m_details << endl;
}