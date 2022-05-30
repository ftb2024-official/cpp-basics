#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> names = {"Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly" };
	bool found = false;

	cout << "Enter a name: ";
	string inputName;
	getline(cin, inputName);

	for(const auto &name: names) {
		if(name == inputName) {
			found = true;
			break;
		}
	}

	found ? cout << inputName << " was found\n" : cout << inputName << " was not found\n";

	return 0;
}