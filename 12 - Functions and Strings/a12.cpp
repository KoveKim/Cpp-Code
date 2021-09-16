// Khristian Kim, CS 135-1003, Assignment 12
// Read file data, check for palindromes, and process strings to palindromes.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string process(string);

bool is_palindrome(string);

int palindrome_fix_location(string);

string palindrome_addition(string, int);

int main()
{
	ifstream inFile;
	inFile.open("data");
	string preString;
	int palinLoc = 0;

	while(getline(inFile, preString))
	{
		cout << "\nOriginal line: " << preString << endl;
		cout << "Processed line: " << process(preString) << endl;

		if (is_palindrome(preString) == true)
			cout << "Line is palindrome." << endl;
		else
			cout << "Line is NOT a palindrome." << endl;
			palindrome_fix_location(preString);
			palindrome_addition(preString, palinLoc);
	}

	inFile.close();

	return 0;
}

// Return a string that is lowercase with no punctuation or spacing.
string process(string preString)
{
	string procString;

	for (size_t i = 0; i < preString.length(); i++)
	{
		if (isalnum(preString[i]))
			procString += tolower(preString[i]);
	}

	return procString;
}

// Uses a recursive method to determine if the processed string is a palindrome.
bool is_palindrome(string procString)
{
	string temp = process(procString);
	int length = temp.length();
	string firstChar = temp.substr(0, 1);
	string lastChar = temp.substr((length - 1), 1);

	if (firstChar == lastChar)
	{
		temp = temp.substr((0 + 1), (length - 2));

		if (temp.length() <= 1) // Base case.
			return true;

		return is_palindrome(temp); // Recursion.
	}

	else
		return false;
}

// Return a location where text can be added to the non-palindrome to make it a palindrome.
int palindrome_fix_location(string procString)
{
	string temp = process(procString);

	if (is_palindrome(temp) == false)
	{
		int palinLoc;

		int firstChar = 0, lastChar = temp.length() - 1;
		while (firstChar < lastChar)
		{
			if (temp[firstChar] != temp[lastChar])
			{
				palinLoc = firstChar;

				cout << "Characters to insert at location "
				<< palinLoc << " are ";

				return palinLoc;
			}

			firstChar++;
			lastChar--;
		}
	}

	return 0;
}

// Return the text that needs to be added at the "palinLoc" location.
string palindrome_addition(string procString, int palinLoc)
{
	string temp = process(procString);
	string addedChars;
	string finalString;

	if (is_palindrome(temp) == false)
	{
		int firstChar = 0, lastChar = temp.length() - 1;
		while (firstChar < lastChar)
		{
			do {
				addedChars += temp[lastChar];
				lastChar--;
			} while (temp[firstChar] != temp[lastChar]);

			firstChar++;
		}

		finalString = temp.insert(palinLoc, addedChars);

		cout << addedChars << endl;
		cout << "Final word: " << finalString << endl;

		return finalString;
	}

	return temp;
}
