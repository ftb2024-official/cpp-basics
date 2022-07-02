#include <iostream>

using namespace std;

class Vector3D;

class Point3D {
private:
	double m_x, m_y, m_z;
public:
	Point3D(double x = 0.0, double y = 0.0, double z = 0.0): m_x{x}, m_y{y}, m_z{z} {}

	void print() {
		cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

	void moveByVector(const Vector3D &vector);
};

class Vector3D {
private:
	double m_x, m_y, m_z;
public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0): m_x{x}, m_y{y}, m_z{z} {}

	void print() {
		cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

	friend void Point3D::moveByVector(const Vector3D &vector);
};

void Point3D::moveByVector(const Vector3D &vector) {
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}

int main(int argc, const char *argv[]) {
	Point3D point(3.0, 4.0, 5.0);
	Vector3D vector(3.0, 3.0, -2.0);

	point.print();
	point.moveByVector(vector);
	point.print();
	
	return 0;
}