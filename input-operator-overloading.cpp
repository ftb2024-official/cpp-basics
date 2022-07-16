#include <iostream>

using namespace std;

class Point {
private:
	double m_x, m_y, m_z;
public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0): m_x{x}, m_y{y}, m_z{z} {}

	friend ostream& operator<<(ostream &out, const Point &point);
	friend istream& operator>>(istream &in, Point &point);
};

ostream& operator<<(ostream &out, const Point &point) {
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")\n";

	return out;
}

istream& operator>>(istream &in, Point &point) {
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in;
}

int main(int argc, const char *argv[]) {
	cout << "Enter a point: \n";

	Point point;
	cin >> point;

	cout << "You entered: " << point << '\n';
	
	return 0;
}