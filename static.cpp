#include <iostream>

using namespace std;

void incAndPrint() {
	int value(1);
	++value;

	cout << value << endl;
}

void incAndPrintStatic() {
	static int value(1);
	++value;

	cout << "static: " << value << endl;
}

int main() {
	incAndPrint();
	incAndPrintStatic();
	
	incAndPrint();
	incAndPrintStatic();
	
	incAndPrint();
	incAndPrintStatic();

	return 0;
}