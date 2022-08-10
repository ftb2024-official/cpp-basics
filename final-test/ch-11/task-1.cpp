#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature {
protected:
	string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	Creature(string name, char symbol, int health, int damage, int gold): m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold} {}
	
	string& getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

	void reduceHealth(int damageAmount) { m_health -= damageAmount; }
	bool isDead() {
		return m_health <= 0 ? true : false;
	}
	void addGold(int goldAmount) { m_gold += goldAmount; }
};

class Player: public Creature {
private:
	int m_level = 1;
public:
	Player(string name): Creature(name, '@', 10, 1, 0) {}
	int getLevel() { return m_level; }

	void levelUp() {
		++m_level;
		++m_damage;
	}
	bool hasWon() { return m_level >= 20; }

};

class Monster: public Creature {
public:
	enum Type {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

	struct MonsterData {
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];

	static Monster getRandomMonster() {
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}

	Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES] {
	{"dragon", 'D', 20, 4, 100},
	{"orc", 'O', 4, 2, 25},
	{"slime", 's', 1, 1, 10}
};

void attackMonster(Player &p, Monster &m) {
	if(p.isDead()) return;

	cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
	m.reduceHealth(p.getDamage());

	if(m.isDead()) {
		cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		cout << "You are now level " << p.getLevel() << ".\n";
		cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}

int main(int argc, const char *argv[]) {
	srand(static_cast<unsigned int>(time(0)));

	for(int i = 0; i < 10; ++i) {
		Monster m = Monster::getRandomMonster();
		cout << "A/An " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}
	
	return 0;
}