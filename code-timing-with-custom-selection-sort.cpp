#include <iostream>
#include <array>
#include <chrono>
#include <algorithm>

using namespace std;

const int arrElems = 10000; // total number of elements in array

class Timer {
private:
	// type aliases are used to easily access nested types
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> m_beg;
public:
	Timer(): m_beg{clock_t::now()} {}

	void reset() { m_beg = clock_t::now(); }

	double elapsed() const {
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray(array<int, arrElems> &array) {
	for(int startIndex = 0; startIndex < arrElems - 1; ++startIndex) {
		int smallestIndex = startIndex;

		for(int currentIndex = startIndex + 1; currentIndex < arrElems; ++currentIndex) {
			if(array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}

		swap(array[startIndex], array[smallestIndex]);
	}
}

int main(int argc, const char *argv[]) {
	array<int, arrElems> array;

	for(int i = 0; i < arrElems; ++i) {
		array[i] = arrElems - i;
	}

	Timer t;
	sort(array.begin(), array.end());

	cout << "Time taken: " << t.elapsed() << "\n";
	
	return 0;
}