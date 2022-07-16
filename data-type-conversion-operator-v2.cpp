#include <iostream>

using namespace std;

class A {
private:
	int m_val;
public:
	A(): m_val{0} { cout << "constructor A() called\n"; }
	A(int val): m_val{val} { cout << "constructor A(val) called\n"; }
	A(const A &copyObj): m_val{copyObj.getVal()} { cout << "copy constructor A(const A &copyObj)\n"; }

	const int& getVal() const { return m_val; }

	A& operator=(const A &right) {
		cout << "assignment operator A& operator=(const A &right)\n";
		if(this == (&right)) {
			return *this;
		}

		m_val = right.getVal();
		return *this;
	}
};

class B {
private:
	A m_objA;
public:
	const A& getA() const { return m_objA; }

	B(): m_objA{} { cout << "constructor B() called\n"; }
	B(const int &val): m_objA{val} { cout << "constructor B(const int &val) called\n"; }
	B(const A &objA): m_objA{objA} { cout << "constructor B(const A &objA) called\n"; }
	B(const B &copyObj): m_objA{copyObj.getA()} { cout << "copy constructor B(const B &copyObj)\n"; }

	operator A() {
		cout << "data type conversion operator A is called\n";
		// return A(m_objA.getVal());
		return m_objA;
	}
};

int main(int argc, const char *argv[]) {
	A a1(12);
	cout << "a1.getVal() = " << a1.getVal() << '\n\n';

	B b1(333); // перврй инициализируется переменная "m_objA", потом сам объект класса "B", поэтому вызывается конструктора

	cout << "b1.getA().getVal() = " << b1.getA().getVal() << '\n\n';

	a1 = b1;

	cout << "a1.getVal() = " << a1.getVal() << '\n';
	
	return 0;
}