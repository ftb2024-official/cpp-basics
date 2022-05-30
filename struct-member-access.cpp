#include <iostream>

using namespace std;

struct Man {
	int weight;
	int height;
};

int main() {
	Man man;

	man.weight = 190;

	cout << "Man's initial weight was: " << man.weight;

	Man &ref_man = man;
	ref_man.weight = 200;

	Man *ptr_man = &man;
	(*ptr_man).weight = 210;
	ptr_man -> weight = 220;

	cout << "\nMan's weigth now: " << man.weight;

	return 0;
}
