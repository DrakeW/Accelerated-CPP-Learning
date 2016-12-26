#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::sort;
using std::vector;

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	double temp;
	vector<double> homeworks;

	while (cin >> temp)
		homeworks.push_back(temp);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homeworks.size();

	if (size == 0) {
		cout << "Your must enter your grades. "
				"Please try again." << endl;
		return 1;
	}

	sort(homeworks.begin(), homeworks.end());

	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homeworks[mid] + homeworks[mid-1])/2 : homeworks[mid];

	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;

	return 0;
}