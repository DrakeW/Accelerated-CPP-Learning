#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name: ";

	string name; // define name
	cin >> name; // read into

	const string greeting = "Hello, " + name + "!";

	cout << "Please enter your preferred padding (integer): ";

	int pad;
	cin >> pad;

	const int rows = pad * 2 + 3;

	cout << endl;

	const string::size_type cols = greeting.size() + pad * 2 + 2;

	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;
		while (c != cols) {
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			} else {
				// write one or more nonborder characters
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
					cout << "*";
				} else {
					cout << " ";
				}
				++c;
			}
		}
		// write a row of output
		cout << endl;
	}
	return 0;
}