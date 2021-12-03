#include "Error.hpp"
#include <iostream>

#include "Basic.hpp"

using std::cout;
using std::endl;
using std::string;

using namespace Basic;

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
    cout << " : " << m_details << endl;
}