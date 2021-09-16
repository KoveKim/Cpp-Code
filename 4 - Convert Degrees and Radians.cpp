// Khristian Kim, CS 135-1003
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Ask the user for their name.
	cout << "Enter your name: ";
	string name;
	cin >> name;

	const double pi = 3.141593;

	// Ask the user for a value in degrees, then convert to radians.
	cout << name << ", enter degrees: ";
	int degs;
	cin >> degs;
	cout << name << ", " << degs << " degrees = " << (degs * pi) / 180
	<< " radians." << endl;

	// Ask the user for a value in radians, then convert to degrees.
	cout << name << ", enter radians: ";
	double rads;
	cin >> rads;
	cout << name << ", " << rads << " radians = "
	<< static_cast<int>((rads * 180) / pi) << " degrees." << endl;

	return 0;
}
