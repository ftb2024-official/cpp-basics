#include <iostream>
#include <string>

using namespace std;

enum class MonsterType {
	Ogre,
	Goblin,
	Skeleton,
	Orc,
	Troll
};

struct Monster {
	MonsterType type;
	string name;
	int health;
};

string getMonster(Monster monster) {
	if(monster.type == MonsterType::Ogre)
		return "Ogre";
	else if(monster.type == MonsterType::Goblin)
		return "Goblin";
	else if(monster.type == MonsterType::Skeleton)
		return "Skeleton";
	else if(monster.type == MonsterType::Orc)
		return "Orc";
	else if(monster.type == MonsterType::Troll)
		return "Troll";
	else
		return "Unknown";
}

void printMonster(Monster monster) {
	cout << "This " << getMonster(monster) << " is named " << monster.name << " and has " << monster.health << "\% health.\n";
}

int main() {
	Monster goblin { MonsterType::Goblin, "John", 170 };
	Monster orc = { MonsterType::Orc, "James", 35 };

	printMonster(goblin);
	printMonster(orc);

	return 0;
}