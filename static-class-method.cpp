#include <iostream>

using namespace std;

class GeneratorID {
private:
	static int sm_nextID;
public:
	static int getNextID();
};

int GeneratorID::sm_nextID = 1;

int GeneratorID::getNextID() { return sm_nextID++; }

int main(int argc, const char *argv[]) {
	for(int count = 0; count < 4; ++count) {
		cout << "the next ID is: " << GeneratorID::getNextID() << "\n";
	}
	
	return 0;
}