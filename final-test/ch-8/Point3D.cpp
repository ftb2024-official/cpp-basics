#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

using namespace std;

void Point3D::print() {
	cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

void Point3D::moveByVector(const Vector3D &vector) {
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}
