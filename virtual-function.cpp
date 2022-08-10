#include <iostream>

using namespace std;

class Animal {
protected:
	string m_name;

	Animal(string name): m_name{name} {}
public:
	string getName() { return m_name; }
	virtual const char* speak() { return "???"; }
};

class Cat: public Animal {
public:
	Cat(string name): Animal(name) {}
	virtual const char* speak() { return "Meow"; }
};

class Dog: public Animal {
public:
	Dog(string name): Animal(name) {}
	virtual const char* speak() { return "Woof"; }
};

void report(Animal &animal) {
	cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main(int argc, const char *argv[]) {
	Cat cat("Matros");
	Dog dog("Barsik");

	report(cat);
	report(dog);
	
	return 0;
}
