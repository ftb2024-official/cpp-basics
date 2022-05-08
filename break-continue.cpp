#include <iostream>

using namespace std;

int main() {
	int count(0);
	bool exitLoop(false);

	// while(!exitLoop) {
	// 	cout << "Enter 'e' to exit this loop or any other key to continue: ";
	// 	char bc;
	// 	cin >> bc;

	// 	if(bc == 'e')
	// 		exitLoop = true;
	// 	else {
	// 		++count;
	// 		cout << "We've iterated " << count << " times.\n";
	// 	}
	// }

	while(true) {
		cout << "Enter 'e' to exit this loop or any other key to continue: ";
		char bc;
		cin >> bc;

		if(bc == 'e')
			break;

		++count;
		cout << "We've iterated " << count << " times.\n";
	}

	return 0;
}