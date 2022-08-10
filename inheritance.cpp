#include <iostream>

using namespace std;

class Parent {
	int m_private;
public:
	int m_public;
protected:
	int m_protected;
};

class D2: private Parent {
	int m_private2;
public:
	int m_public2;
protected:
	int m_protected2;
};

class D3: public D2 {
	int m_private3;
public:
	int m_public3;
protected:
	int m_protected3;
};

int main(int argc, const char *argv[]) {
	
	return 0;
}