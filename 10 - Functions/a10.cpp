// Khristian Kim, CS 135-1003, Assignment 10
// Read from data, output them as processed string and original string.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string process(string);

// This function simply inputs data (strings) from the input file.
int main()
{
	ifstream inFile;
	inFile.open("data");

	string orig;

	while (getline(inFile, orig))
	{
		cout << "Original string: " << orig << endl;
		string proc = orig;
		cout << "Processed string: " << process(proc) << endl;
	}

	inFile.close();
	return 0;
}

// This function will "process" the original string.
string process(string proc)
{
	for (int i = 0; proc[i]; i++)
	{
		if (proc[i - 1] == ' ' || i == 0 || i == 1)
			proc[i] = toupper(proc[i]);
		if (proc[i - 2] == ' ' || i == 0 || i == 1)
			proc[i] = toupper(proc[i]);
	}
	return proc;
}
