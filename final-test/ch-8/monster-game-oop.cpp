#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Monster {
public:
	enum MonsterType {
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};
private:
	MonsterType m_type;
	string m_name;
	int m_health;
public:
	Monster(MonsterType type, string name, int health): m_type{type}, m_name{name}, m_health{health} {}

	string getTypeString() {
		switch(m_type) {
			case Dragon: return "dragon";
			case Goblin: return "goblin";
			case Ogre: return "ogre";
			case Orc: return "orc";
			case Skeleton: return "troll";
			case Vampire: return "vampire";
			case Zombie: return "zombie";
		}
		return "Error!";
	}

	void print() {
		cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points.\n";
	}
};

class MonsterGenerator {
public:
	static Monster generateMonster() {
		Monster::MonsterType type = static_cast<Monster::MonsterType>(
			getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)
		);
		
		int health = getRandomNumber(1, 100);

		static string s_names[6] {"James", "Robert", "John", "Mary", "Patricia", "Jennifer"};

		return Monster(type, s_names[getRandomNumber(0, 5)], health);
	}

	static int getRandomNumber(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};

int main(int argc, const char *argv[]) {
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();

	m.print();
	
	return 0;
}