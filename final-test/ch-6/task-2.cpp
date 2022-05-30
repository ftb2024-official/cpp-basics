#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
	string name;
	int score;
};

void sortNames(Student *students, int length) {
	for(int startIndex = 0; startIndex < length; ++startIndex) {
		int largestIndex = startIndex;

		for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
			if(students[currentIndex].score > students[largestIndex].score)
				largestIndex = currentIndex;
		}

		swap(students[startIndex], students[largestIndex]);
	}
}

int main() {
	cout << "How many students in class?: ";
	unsigned int quantity;
	cin >> quantity;
	cin.ignore(32767, '\n');

	Student *students = new Student[quantity];

	for(int index = 0; index < quantity; ++index) {
		cout << "Enter name #" << index + 1 << ": ";
		getline(cin, students[index].name);

		cout << "Enter " << students[index].name << "'s score: ";
		cin >> students[index].score;
		cin.ignore(32767, '\n');
	}

	cout << "\n";

	sortNames(students, quantity);

	// выводим имена студентов и их оценки
	for(int index = 0; index < quantity; ++index) {
		cout << students[index].name << "'s grade is " << students[index].score << endl;
	}

	delete[] students; // не забываем об освобождении памяти

	return 0;
}