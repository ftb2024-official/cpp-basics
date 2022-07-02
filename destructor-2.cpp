#include <iostream>

using namespace std;

class Another {
private:
	int m_nID;
public:
	Another(int nID): m_nID{nID} {
		cout << "Constructing Another " << nID << "\n";
	}

	~Another() { cout << "Destructing Another " << m_nID << "\n"; }

	int getID() { return m_nID; }
};

int main(int argc, const char *argv[]) {
	Another object(1);
	cout << object.getID() << "\n";

	Another *ptrObject = new Another(2);
	cout << ptrObject->getID() << "\n";

	delete ptrObject;
	
	return 0;
}