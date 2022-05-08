#include <iostream>
#include <string>

using namespace std;

enum ItemType {
	GUN,
	ARBALET,
	SWORD
};

string getItemName(ItemType item) {
	if(item == GUN)
		return "Gun";
	if(item == ARBALET)
		return "Arbalet";
	if(item == SWORD)
		return "Sword";

	return "Non-existing weapon";
}

int main() {
	ItemType item_type(ARBALET);

	cout << "You're carrying a " << getItemName(item_type) << endl;

	return 0;
}