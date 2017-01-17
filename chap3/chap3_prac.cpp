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
	// 3-3
	cout << "Enter a list of words: ";
	vector<string> words;
	vector<int> word_counts;

	string temp;

	typedef vector<string>::size_type vec_sz;

	while (cin >> temp) {
		vec_sz length = words.size();
		bool existed = false;
		// check for membership
		for (int i = 0; i < length; ++i) {
			string cur_word = words[i];
			if (temp == cur_word) {
				++word_counts[i];
				existed = true;
			}
		}
		if (!existed) {
			words.push_back(temp);
			word_counts.push_back(1);
		}
	}
	// print out summary
	vec_sz count = words.size();
	cout << "Summary" << endl;
	for (int i = 0; i < count; ++i) {
		cout << words[i] << ": " << word_counts[i] << endl;
	}
	return 0;
}