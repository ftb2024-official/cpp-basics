#include <iostream>

using namespace std;

int main() {
	double zero = 0.0;
	double posinf = 5.0 / zero; // положительная беконечность

	double neginf = -5.0 / zero; // отрицательная беконечность

	double nan = zero / zero; // не число (математически некорректно)

	cout << posinf << endl;
	cout << neginf << endl;
	cout << nan << endl;

	return 0;
}