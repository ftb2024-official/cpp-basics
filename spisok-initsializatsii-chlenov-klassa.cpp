#include <iostream>

using namespace std;

class A {
public:
	A(int a) { cout << "A: " << a << endl; }
};

class B {
private:
	A m_a;
public:
	B(int b): m_a(b - 1) { cout << "B: " << b << endl; }
};

int main(int argc, char const *argv[]) {
	B b(7);
	
	return 0;
}
