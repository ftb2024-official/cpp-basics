#include <iostream>
#include <string>

using namespace std;

class Ball {
private:
	string m_color;
	double m_radius;
public:
	Ball(string color = "red", double radius = 20.0) {
		m_color = color;
		m_radius = radius;
	}
	
	Ball(double radius) {
		m_radius = radius;
		m_color = "red";
	}

	void print() {
		cout << "color: " << m_color << ", radius: " << m_radius << endl;
	}
};

int main(int argc, char const *argv[]) {
	Ball def;
	def.print();

	Ball black("black");
	black.print();

	Ball thirty(30.0);
	thirty.print();

	Ball blackThirty("black", 30.0);
	blackThirty.print();
	
	return 0;
}
