#include <iostream>

using namespace std;

class Point {
private:
	double m_x, m_y, m_z;
public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0): m_x{x}, m_y{y}, m_z{z} {}

	friend ostream& operator<<(ostream &out, const Point &point);
};

ostream& operator<<(ostream &out, const Point &point) {
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")\n";

	return out;
}

int main(int argc, const char *argv[]) {
	Point point1(5.0, 6.0, 7.0);

	cout << point1;
	
	return 0;
}