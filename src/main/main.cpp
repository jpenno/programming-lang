#include <iostream>
#include <string.h>
#include "add.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, const char *argv[])
{
	cout << "Program start:" << endl;
	bool run = true;
	string text;

	while (run)
	{
		cout << "basic > ";
		getline(cin, text);
		cout << text << endl;

		if (text == "exit")
		{
			run = false;
		}
	}

	return 0;
}
