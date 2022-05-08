#include <iostream>
#include <cmath>

using namespace std;

int main() {
	// int outer = 5;

	// while(outer > 0) {
	// 	int inner = outer;

	// 	while(inner > 0)
	// 		cout << inner-- << " ";

	// 	cout << "\n";

	// 	--outer;
	// }

	int outer = 1;

	while(outer <= 5) {
		int inner = 5;

		while(inner >= 1) {
			if(inner <= outer)
				cout << inner << " ";
			else
				cout << "  ";

			--inner;
		}

		cout << "\n";

		++outer;
	}
	
	return 0;
}