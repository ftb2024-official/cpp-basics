#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

using namespace std;

class Point2D {
private:
	int m_x, m_y;
public:
	Point2D(): m_x{0}, m_y{0} {}
	Point2D(int x, int y): m_x{x}, m_y{y} {}

	friend ostream& operator<<(ostream &out, const Point2D &point) {
		out << "(" << point.m_x << ", " << point.m_y << ")";
		return out;
	}

	void setPoint(int x, int y) {
		m_x = x;
		m_y = y;
	}
};

#endif