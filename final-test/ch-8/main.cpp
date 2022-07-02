#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

using namespace std;

int main(int argc, const char *argv[]) {
	Point3D point(3.0, 4.0, 5.0);
	Vector3D vector(3.0, 3.0, -2.0);

	point.print();
	point.moveByVector(vector);
	point.print();
	
	return 0;
}
