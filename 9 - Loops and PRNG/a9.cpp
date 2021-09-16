// Khristian Kim, CS 135-1003, Assignment 09
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Part 1 of program - standard deviation calculation.
	cout << "\n***Standard deviation calculation***" << endl;

	ifstream inFile;
	inFile.open("data");
	int theValueNum = 1;
	double value;
	string theValue = "Value #";

	// For the first set of means.
	double x; // Copies variable "value" but sums the results.
	int amount;
	while (inFile >> value)
	{
		amount++;
		cout << theValue << theValueNum++ << ": " << value << endl;
		x = x + value;
	}

	double mean1 = x / amount;
	inFile.clear();
	inFile.seekg(0);

	// For the second set of means.
	double y, z; // "y" is the squared result. "z" is the saved value.
	while (inFile >> value)
	{
		y = pow((value - mean1), 2);
		z = z + y;
	}

	double mean2 = z / (amount - 1);
	double finalNum = sqrt(mean2);
	cout << "Sample standard deviation: " << finalNum << endl << endl;

	inFile.close();

	// Part 2 of program - Craps simulation.
	cout << "***Craps simulation***" << endl;

	srand(time(0)); // Current system time.
	int die1, die2, sum, rollCount = 0;
	int noPass = 0, pass = 0, point = 0;

	// Roll the dice, record the numbers until 1,000,000 trials are made.
	while (rollCount < 1000000)
	{
		die1 = (rand() % 6 + 1);
		die2 = (rand() % 6 + 1);
		sum = die1 + die2;

		if (sum == 2 || sum == 3 || sum == 12)
			noPass++, rollCount++;
		else if (sum == 7 || sum == 11)
			pass++, rollCount++;
		else point++, rollCount++;
	}

	cout << rollCount << " trials conducted" << setprecision(4);
	cout << "\nPass: " << pass << "/" << rollCount << " "
	<< (static_cast<double>(pass) / static_cast<double>(rollCount)) * 100
	<< "%";
	cout << "\nDon't pass: " << noPass << "/" << rollCount << " "
	<< (static_cast<double>(noPass) / static_cast<double>(rollCount)) * 100
	<< "%";
	cout << "\nPoint established: " << point << "/" << rollCount << " "
	<< (static_cast<double>(point) / static_cast<double>(rollCount)) * 100
	<< "%" << endl << endl;

	return 0;
}
