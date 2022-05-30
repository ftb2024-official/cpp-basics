#include <iostream>

using namespace std;

enum ItemTypes {
	HEALTH_POTION,
	TORCH,
	ARROW,
	MAX_ITEMS
};

int countTotalItems(int *items) {
	int totalItems = 0;
	for(int index = 0; index < MAX_ITEMS; ++index)
		totalItems += items[index];

	return totalItems;
}

int main() {
	int items[MAX_ITEMS] = {3, 6, 9}; // указываем стартовое кол-во предметов, который имеет при себе игрок

	cout << "The player has " << countTotalItems(items) << " items in total\n";
	cout << TORCH << " MAX_ITEMS" << MAX_ITEMS;

	return 0;
}