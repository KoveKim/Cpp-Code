// Khristian Kim, CS 135-1003

#include <iostream>
#include <string>
using namespace std;

int main()
{
	double x, y, z;

	cout << "Enter the first value: ";
	cin >> x;

	cout << "Enter the second value: ";
	cin >> y;

	cout << "Enter the third value: ";
	cin >> z;

	cout << "\nYour input is: " << x << ", " << y << ", and "  << z << endl;
	cout << "The average is: " << (x + y + z) / 3 << endl;

	return 0;
}
