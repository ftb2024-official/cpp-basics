#include <iostream>
#include "global.h"

extern const int EXTERN_CONST = 2;

void printStaticConst() {
	std::cout << STATIC_CONST << " [ " << &STATIC_CONST << " ]\n";
}

void printExternConst() {
	std::cout << EXTERN_CONST << " [ " << &EXTERN_CONST << " ]\n";
}