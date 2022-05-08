#include <iostream>
#include "constants.h"

using namespace std;

int main() {
	double currentHeight, distanceFallen;
	int time = 0;

	cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	cin >> initialHeight;

	currentHeight = initialHeight;

	while(currentHeight > 0) {
		distanceFallen = (myConstants::gravity * time * time) / 2;
		currentHeight = initialHeight - distanceFallen;

		if(distanceFallen >= initialHeight) {
			cout << "At " << time << " seconds, the ball is on the ground.\n";
		} else {
			cout << "At " << time << " seconds, the ball is at height: " << currentHeight << " meters.\n";
		}

		time++;
	}

	return 0;
}
