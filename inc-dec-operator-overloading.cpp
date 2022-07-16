#include <iostream>

using namespace std;

class Number {
private:
	int m_num;
public:
	Number(int num): m_num{num} {}

	Number& operator++() {
		if(m_num == 8) {
			m_num = 0;
		} else {
			++m_num;
		}

		return *this;
	}

	Number& operator--(); // prefix version

	Number operator++(int); // postfix version

	Number operator--(int) {
		// creating a temporary object of class Number with the current value of the member "m_num"
		Number temp(m_num);

		// using the prefix version decrement operator to implement an overload of the postfix version decrement operator
		--(*this);

		// returning temporary object
		return temp;
	}
	
	friend ostream& operator<<(ostream &out, const Number &num) {
		out << num.m_num << ' ';
		return out;
	}
};

Number& Number::operator--() {
	if(m_num == 0) {
		m_num = 8;
	} else {
		--m_num;
	}

	return *this;
}

Number Number::operator++(int) {
	Number temp(m_num);

	++(*this);

	return temp;
}

int main(int argc, const char *argv[]) {
	Number num(6);

	// cout << num << ++num << num++ << num << --num << num-- << num << endl;

	cout << num;
	cout << ++num;
	cout << num++;
	cout << num;
	cout << --num;
	cout << num--;
	cout << num;
	
	return 0;
}