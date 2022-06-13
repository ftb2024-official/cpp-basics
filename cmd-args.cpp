#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc <= 1) {
		if(argv[0])
			cout << "Usage: " << argv[0] << " <number>\n";
		else
			cout << "Usage: <program name> <number>\n";

		exit(1);
	}

	stringstream convert(argv[1]);
	int myint;

	if(!(convert >> myint))
		myint = 0;

	cout << "Got integer: " << myint << endl;

	return 0;
}