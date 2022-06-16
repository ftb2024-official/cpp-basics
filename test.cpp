#include <iostream>

using namespace std;

class Numbers {
private:
	double m_a, m_b, m_c;

public:
	void setValues(double a, double b, double c) {
		m_a = a;
		m_b = b;
		m_c = c;
	}

	void print() {
		cout << "<" << m_a << ", " << m_b << ", " << m_c << ">\n";
	}

	bool isEqual(const Numbers &nums) {
		return (m_a == nums.m_a && m_b == nums.m_b && m_c == nums.m_c);
	}
};

int main(int argc, char *argv[]) {
	Numbers point1;
	point1.setValues(3.0, 4.0, 5.0);

	Numbers point2;
	point2.setValues(3.0, 4.0, 5.0);

	if(point1.isEqual(point2))
		cout << "point1 and point2 are equal\n";
	else
		cout << "point1 and point2 aren't equal\n";

	Numbers point3;
	point3.setValues(7.0, 8.0, 9.0);

	if(point1.isEqual(point3))
		cout << "point1 and point3 are equal\n";
	else
		cout << "point1 and point3 aren't equal\n";
	
	return 0;
}

// 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