#include <iostream>
#include "global.h"

using namespace std;

int main() {
	cout << "Static const address: \n";
	cout << STATIC_CONST << " [ " << &STATIC_CONST << " ]\n";
	printStaticConst();

	cout << "\nExtern const address: \n";
	cout << EXTERN_CONST << " [ " << &EXTERN_CONST << " ]\n";
	printExternConst();

	return 0;
}