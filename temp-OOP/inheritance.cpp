#include <iostream>

using namespace std;

class Car {
private:
	int Price;
	string Color;
	string Model;
public:
	Car(string model, string color, int price) {
		Model = model;
		Color = color;
		Price = price;
	}
	
	void start() {
		cout << "Engine started!\n";
	}

	void stop() {
		cout << "Engine stopped!\n";
	}
};

class Electric: Car {
private:
	int Battery;
public:
	Electric(string model, string color, int price, int battery):Car(model, color, price) {
		Battery = battery;
	}

	void batteryPercentage() {
		cout << Battery << " \% left";
	}
};

class Ordinary: Car {
private:
	int Fuel;
public:
	Ordinary(string model, string color, int price, int fuel):Car(model, color, price) {
		Fuel = fuel;
	}

	void fuelLeft() {
		cout << Fuel << " L of fuel left";
	}
};

int main() {
	Ordinary ferrari = Ordinary("La Ferrari", "Red", 3000000, 100);
	Electric tesla = Electric("S Plaid", "Black", 150000, 99);

	ferrari.fuelLeft();
	tesla.batteryPercentage();

	return 0;
}