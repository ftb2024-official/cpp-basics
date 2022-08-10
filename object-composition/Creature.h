#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2D.h"

using namespace std;

class Creature {
private:
	string m_name;
	Point2D m_location;
public:
	Creature(const string &name, const Point2D &location): m_name{name}, m_location{location} {}

	friend ostream& operator<<(ostream &out, const Creature &creature) {
		out << creature.m_name << " is at " << creature.m_location;
		return out;
	}

	void moveTo(int x, int y) {
		m_location.setPoint(x, y);
	}
};

#endif