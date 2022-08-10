// Для реализации агрегации целое и его части должны соответствовать следующим отношениям:
// => Часть (член) яаляется частью целого (класса)
// => Часть (член) может принадлежать более чем одному целому (классу) в моменте
// => Часть (член) существует, не управляемая целым (классом)
// => Часть (член) не знает о существовании целого (класса)

#include <iostream>
#include <string>

using namespace std;

class Worker {
private:
	string m_name;
public:
	Worker(string name): m_name{name} {}

	string getName() { return m_name; }
};

class Department {
private:
	Worker *m_worker;
public:
	Department(Worker *worker = nullptr): m_worker{worker} {}
};

int main(int argc, const char *argv[]) {
	Worker *worker = new Worker("Anton");

	{
		// создаём Отдел и передаём Работника в Отдел через параметр конструктора
		Department department(worker);
	} // department выходит из области видимости и уничтожается здесь

	cout << worker->getName() << " still exists\n";

	delete worker;
	
	return 0;
}