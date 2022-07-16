#include <iostream>
#include "Dollars.h"

using namespace std;

int main(int argc, const char *argv[]) {
	Dollars d1(1);
	Dollars d2(10);
	Dollars d3 = d1 + d2;

	cout << "I have " << d3.getDollars() << " dollars\n";
	
	return 0;
}