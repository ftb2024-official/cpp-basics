#include <iostream>

using namespace std;

// class Date {
// private:
// 	int m_day, m_month, m_year;
// public:
// 	Date(int day = 29, int month = 6, int year = 1999): m_day{day}, m_month{month}, m_year{year} {}

// 	void changeYear() { m_year += 100; }

// 	void getDate() const {
// 		cout << "the date: " << m_day << "." << m_month << "." << m_year << "\n";
// 	}

// 	int getYear() const;
// };

// int Date::getYear() const { return m_year; }

/* Константы и ссылки */
class Date {
private:
	int m_day, m_month, m_year;
public:
	Date(int day, int month, int year) {
		setDate(day, month, year);
	}

	void setDate(int day, int month, int year) {
		m_day = day;
		m_month = month;
		m_year = year;
	}

	int getDay() const { return m_day; }
	int getMonth() const { return m_month; }
	int getYear() const { return m_year; }
};

void printDate(const Date &date) {
	cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << "\n";
}

int main(int argc, const char *argv[]) {
	// const Date birthday;
	// birthday.getDate();

	/* Константы и ссылки */
	Date today(30, 6, 2022);
	printDate(today);	

	return 0;
}