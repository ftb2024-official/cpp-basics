#include <iostream>
#include <cassert>

using namespace std;

class Stack {
private:
	int m_arr[10];
	int m_next;
public:
	void reset() {
		m_next = 0;
		for(int i = 0; i < 10; ++i)
			m_arr[i] = 0;
	}

	bool push(int value) {
		if(m_next == 10)
			return false;

		m_arr[m_next++] = value;
		return true;
	}

	int pop() {
		assert(m_next > 0);

		return m_arr[--m_next];
	}

	void print() {
		cout << "( ";
		for(int i = 0; i < m_next; ++i)
			cout << m_arr[i] << " ";
		cout << ")\n";
	}
};

int main() {
	Stack stack;

	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}