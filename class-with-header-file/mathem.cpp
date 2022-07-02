#include <iostream>
#include "mathem.h"

using namespace std;

Mathem::Mathem(int value): m_value{value} {}

Mathem& Mathem::add(int value) {
	m_value += value;
	return *this;
}

Mathem& Mathem::sub(int value) {
	m_value -= value;
	return *this;
}

Mathem& Mathem::mult(int value) {
	m_value *= value;
	return *this;
}

int main(int argc, const char *argv[]) {
	Mathem math;
	math.add(3).mult(4).sub(5);

	cout << "result: " << math.getValue();
	
	return 0;
}