/*
Khristian Kim, CS 135-1003, Assignment 7
This program reads data in a postfix, performs the operation, and
appends the result to a different file.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	ifstream data;
	ofstream kimk18;

	// Prompt user for data file to open.
	string userInput;
	cout << "Enter a filename [Example: data(1-7)]: ";
	getline(cin, userInput);
	data.open(userInput.c_str());

	// Setting variables for the values within the input file.
	double x, y;
	const string HYPOT = "hypot";
	const string POW = "pow";
	data >> x >> y;
	string func;

	kimk18.open("kimk18");

	// See if it's a math function first, then check if it's arithmetic.
	if(func == HYPOT)
	{
		kimk18 << x << " " << y << " hypot" << " = " << hypot(x, y) << endl;
	}

	else if(func == POW)
	{
		kimk18 << x << " " << y << " pow" << " = " << pow(x, y) << endl;
	}

	else
	{
		char op;
		string equ;
		data >> op;
		data.close();

		// Check which arithmetic operation we're dealing with.
		if(op == '+')
		{
			kimk18 << x << " " << y << " +" << " = " << x + y << endl;
		}

		else if(op == '-')
		{
			kimk18 << x << " " << y << " -" << " = " << x - y << endl;
		}

		else if(op == '/')
		{
			if(y == 0) // Error if dividing by 0
			{
				kimk18 << x << " " << y << " /" << " = "
				<< "error, division by zero." << endl;
			}

			else
			{
				kimk18 << x << " " << y << " /" << " = "
				<< x / y << endl;
			}
		}

		else if(op == '*')
		{
			kimk18 << x << " " << y << " *" << " = " << x * y << endl;
		}

		else
		{
			kimk18 << "That operator is not supported." << endl;
		}

	}

	kimk18.close();
	return 0;
}
