// Khristian Kim, CS 135-1003, Assignment 08.
// This program displays stuff about an input file.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("data");
	string line;

	while (getline(inFile, line))
	{
		for (int i; i = 0; i++)
		{
			int lineNum = 0;
			char lineEnd;
			if (lineEnd == ('\n'))
				cout << "Line " << lineNum++ << ": ";
			if (string == -1)
				break;
		}
		cout << line << endl;
	}

	inFile.close();
	return 0;
}
