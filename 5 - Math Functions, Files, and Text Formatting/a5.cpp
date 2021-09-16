// Khristian Kim, CS 135-1003, Assignment 05
// Output math data into a file using fstream.

#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// Declare the fstream variables.

	ifstream data;
	ofstream kimk18;

	// Get the x and y input values from the file "data."

	double x, y;
	data.open("data");
	data >> x >> y;
	data.close();

	// Display the variables and their values into the output file.

	kimk18.open("kimk18");
	kimk18 << "x = " << x << "\ny = " << y << endl;

	// Now that we have the values, plug them into math equations
	// and then display them into the output file "kimk18."

	kimk18 << "/" << setw(60) << setfill('-') << "" << "\\";

	kimk18 << "\n| 2^x" << setw(55) << setfill(' ')
	<< fixed << setprecision(10) << pow(2,x) << " |";

	// We only need to use the manipulators once, except "setw."

	kimk18 << "\n| 2^y" << setw(55) << pow(2,y) << " |";

	kimk18 << "\n| log_10 x" << setw(50) << log10(x) << " |";
	kimk18 << "\n| log_10 y" << setw(50) << log10(y) << " |";

	kimk18 << "\n| x^y" << setw(55) << pow(x,y) << " |";
	kimk18 << "\n| y^x" << setw(55) << pow(y,x) << " |";

	kimk18 << "\n| square root of x" << setw(42) << sqrt(x) << " |";
	kimk18 << "\n| square root of y" << setw(42) << sqrt(y) << " |";

	kimk18 << "\n\\" << setw(60) << setfill('-') << "" << "/" << endl;

	// Always close the file you used.

	kimk18.close();
	return 0;
}
