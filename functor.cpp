#include <iostream>

using namespace std;

class Accumulator {
private:
	int m_counter = 0;
public:
	Accumulator() {}

	int operator()(int i) { return m_counter += i; }
};

int main(int argc, const char *argv[]) {
	Accumulator accum;
	
	cout << accum(30) << '\n'; // => 30
	cout << accum(40) << '\n'; // 30 + 40 => 70
	cout << accum(30) << '\n'; // 70 + 30 => 100
	
	return 0;
}