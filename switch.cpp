#include <iostream>
#include <string>

using namespace std;

enum class Animals {
	Pig,
	Chicken,
	Goat,
	Cat,
	Ostrich
};

string getAnimalName(Animals animal) {
	switch(animal) {
		case Animals::Pig: return "Pig";
		case Animals::Chicken: return "Chicken";
		case Animals::Goat: return "Goat";
		case Animals::Cat: return "Cat";
		case Animals::Ostrich: return "Ostrich";
		default: return "Unknown Animal :(";
	}
}

void printNumberOfLegs(Animals animal) {
	switch(animal) {
		case Animals::Pig: cout << "A/An " << getAnimalName(animal) << " has 4 legs.\n"; break;
		case Animals::Chicken: cout << "A/An " << getAnimalName(animal) << " has 2 legs.\n"; break;
		case Animals::Goat: cout << "A/An " << getAnimalName(animal) << " has 4 legs.\n"; break;
		case Animals::Cat: cout << "A/An " << getAnimalName(animal) << " has 4 legs.\n"; break;
		case Animals::Ostrich: cout << "A/An " << getAnimalName(animal) << " has 2 legs.\n"; break;
		default: cout << "Unknown Animal doesn't have any legs :("; break;
	}
}

int main() {
	Animals cat = Animals::Cat;
	Animals chicken = Animals::Chicken;

	printNumberOfLegs(cat);
	printNumberOfLegs(chicken);

	return 0;
}