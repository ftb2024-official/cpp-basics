#include <iostream>

using namespace std;

class A {
public:
	virtual const char* getName() final { return "A"; }
};

class B final: public A {
public:
	const char* getName() { return "B"; }
};

class C: public B {
public:
	C() { cout << "Hello\n"; }
};

int main(int argc, const char *argv[]) {	
	
	return 0;
}