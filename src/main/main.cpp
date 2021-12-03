#include <vector>
#include <iostream>
#include <string.h>

#include "Basic.hpp"
#include "Token.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using namespace Basic;

void PrintVector(vector<Token> a_vector);

int main(int argc, const char *argv[])
{
	cout << "Program start:" << endl;
	bool run = true;
	string text;

	while (run)
	{
		cout << "basic > ";
		getline(cin, text);

		vector<Token> result = Run(text);

		PrintVector(result);

		if (text == "return")
		{
			run = false;
		}
	}

	return 0;
}

void PrintVector(vector<Token> a_vector)
{
	cout << "[ ";
	for (Token i : a_vector)
	{
		i.PrintType();
	}
	cout << " ]" << endl;
}