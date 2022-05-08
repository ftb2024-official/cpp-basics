#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Enter your full name: ";
	string fullName;
	getline(cin, fullName);

	cout << "Enter your age: ";
	int age;
	cin >> age;

	double yearPerLetter = static_cast<double>(age) / fullName.length();

	cout << "You've lived " << yearPerLetter << " years for each letter in your name\n";

	return 0;
}