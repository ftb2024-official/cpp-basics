#include <iostream>
#define PRINT // => "Printing..."

using namespace std;

void doSmth() {
	// #define PRINT // => "Printing..."

	#ifdef PRINT
	cout << "Printing..." << endl;
	#endif

	#ifndef PRINT
	cout << "Not Printing..." << endl;
	#endif

	// #define PRINT // => "Not Printing..."
}

int main() {
	doSmth();

	// #define PRINT // => "Not Printing..."

	doSmth();

	return 0;
}