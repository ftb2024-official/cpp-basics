#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// float f;
	// f = 9.87654321f;
	// cout << f << endl;

	// f = 987.654321f;
	// cout << f << endl;

	// f = 987654.321f;
	// cout << f << endl;

	// f = 9876543.21f;
	// cout << f << endl;

	// f = 0.0000987654321f;
	// cout << f << endl;

	cout << setprecision(17);

	double d1 = 1.0;
	cout << d1 << endl;

	double d2 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1001;
	cout << d2 << endl;

	return 0;
}