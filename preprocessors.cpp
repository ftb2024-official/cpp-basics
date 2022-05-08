#include <iostream>

using namespace std;

#define JOE

int main() {
	#ifdef JOE // if JOE defined
	cout << "JOE" << endl;
	#endif

	#ifndef BOB // if BOB not defined
	cout << "BOB" << endl;
	#endif

	return 0;
}