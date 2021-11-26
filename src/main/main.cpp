#include <iostream>
#include <string.h>
#include "basic.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace Basic;

void PrintVector(vector<Basic::Token> a_vector);

int main(int argc, const char *argv[])
{
	cout << "Program start:" << endl;
	bool run = true;
	string text;

	while (run)
	{
		cout << "basic > ";
		getline(cin, text);

		vector<Basic::Token> result = Basic::Run(text);

		PrintVector(result);

		if (text == "return")
		{
			run = false;
		}
	}

	return 0;
}

void PrintVector(vector<Basic::Token> a_vector)
{
	cout << "[ ";
	for (Basic::Token i : a_vector)
	{
		i.PrintType();
	}
	cout << " ]" << endl;
}