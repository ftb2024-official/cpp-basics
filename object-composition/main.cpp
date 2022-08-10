#include <iostream>
#include <string>
#include "Point2D.h"
#include "Creature.h"

using namespace std;

int main(int argc, const char *argv[]) {
	cout << "Enter a name for your creature: ";
	string name;
	cin >> name;

	Creature creature(name, Point2D(5, 6));

	while(1) {
		cout << creature << '\n';

		cout << "Enter new X location for creature (-1 to quit): ";
		int x = 0;
		cin >> x;
		if(x == -1) break;

		cout << "Enter new Y location for creature (-1 to quit): ";
		int y = 0;
		cin >> y;
		if(y == -1) break;

		creature.moveTo(x, y);
	}
	
	return 0;
}