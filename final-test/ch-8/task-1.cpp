#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
	double m_a, m_b;
public:
	Point(double a = 0.0, double b = 0.0): m_a{a}, m_b{b} {}

	void print() {
		cout << "Point(" << m_a << ", " << m_b << ")\n";
	}

	friend double distanceFrom(const Point &point1, const Point &point2);
};

double distanceFrom(const Point &a, const Point &b) {
	return sqrt((a.m_a - b.m_a) * (a.m_a - b.m_a) + (a.m_b - b.m_b) * (a.m_b - b.m_b));
}

int main(int argc, const char *argv[]) {
	Point first;
	Point second(2.0, 5.0);

	first.print();
	second.print();

	cout << "Distance between two points: " << distanceFrom(first, second) << "\n";
	
	return 0;
}