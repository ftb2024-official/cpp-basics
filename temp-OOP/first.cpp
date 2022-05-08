#include <iostream>

using namespace std;

class IEmployee {
	virtual void askForPromotion() = 0;
};

class Employee: IEmployee {
protected:
	string Name;
	int Age;
	string Company;
public:
	Employee(string name, int age, string company) {
		Name = name;
		Age = age;
		Company = company;
	}

	/* Setters */
	void setName(string newName) { Name = newName; }
	void setAge(int newAge) { Age = newAge; }
	void setCompany(string newCompany) { Company = newCompany; }

	/* Getters */
	string getName() { return Name; }
	int getAge() { return Age; }
	string getCompany() { return Company; }

	void introduce() {
		cout << "Hello, I'm " << Name << " , I'm " << Age << " years old and I work for " << Company << endl;
	}

	void askForPromotion() {
		(Age < 30) ? cout << Name << " not ready for promotion, yet!\n" : cout << Name << " got promoted!\n";
	}

	virtual void work() {
		cout << Name << " is checking emails, and doing other stuff" << endl;
	}
};

class Developer: public Employee {
private:
	string favProgLang;
public:
	Developer(string name, int age, string company, string language):Employee(name, age, company) {
		favProgLang = language;
	}

	void favLang() {
		cout << Name << "'s favorite programming language: " << favProgLang << endl;
	}

	void work() {
		cout << Name << " is writing " << favProgLang << " code" << endl;
	}
};

class Teacher: public Employee {
private:
	string Subject;
public:
	Teacher(string name, int age, string company, string subject):Employee(name, age, company) {
		Subject = subject;
	}
	void prepareLesson() {
		cout << Name << " is preparing " << Subject << " lesson" << endl;
	}

	void work() {
		cout << Name << " is teaching " << Subject << endl;
	}
};

int main() {
	//Employee employee = Employee("Someone", 22, "Rainbow");
	Developer d = Developer("Gilfoyle", 35, "Pied Piper", "C++");
	Teacher t = Teacher("Jack", 37, "School", "Math");

	Employee* employee = &d;
	Employee* employee2 = &t;

	employee -> work();
	employee2 -> work();

	return 0;
}
