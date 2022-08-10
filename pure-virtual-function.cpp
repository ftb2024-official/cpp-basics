#include <iostream>

using namespace std;

class Animal {
protected:
	string m_name;
public:
	Animal(string name): m_name{name} {}

	string getName() { return m_name; }
	virtual const char* speak() = 0;
};

class Lion: public Animal {
public:
	Lion(string name): Animal(name) {}

	virtual const char* speak() { return "RAWRR"; }
};

int main(int argc, const char *argv[]) {
	Lion lion("John");

	cout << lion.getName() << " says " << lion.speak() << '\n';
	
	return 0;
}