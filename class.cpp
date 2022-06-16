#include <iostream>

using namespace std;

class Numbers {
public:
	int m_num1;
	int m_num2;

	void set(int n1, int n2) {
		m_num1 = n1;
		m_num2 = n2;
	}

	void print() {
		cout << "Class Numbers(" << m_num1 << ", " << m_num2 << ")\n";
	}
};

/* struct */
struct NumbersStruct {
	int num1;
	int num2;
};

void set(NumbersStruct &num, int n1, int n2) {
	num.num1 = n1;
	num.num2 = n2;
}

void print(NumbersStruct numStruct) {
	cout << "Struct Numbers(" << numStruct.num1 << ", " << numStruct.num2 << ")\n";
}
/* struct */

int main() {
	NumbersStruct struct_n1;
	set(struct_n1, 3, 3);

	NumbersStruct struct_n2 {5, 5};

	Numbers n3;
	n3.set(7, 7);

	Numbers n4 {11, 11};

	print(struct_n1);
	print(struct_n2);

	cout << endl;
	
	n3.print();
	n4.print();

	return 0;
}