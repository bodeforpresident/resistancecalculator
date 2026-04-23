#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

double parEq(double& resistor, vector<double>& resistors); // parallel Rt function
double serEq(vector<double>& resistors); // series Rt function
void serVEq(vector<double>& resistors, double sourceV, double sRT); // voltage drop function
void parCEq(vector<double>& resistors, double sourceV); // current function

int main() {
	// variables
	double resistor;
	int resistorAmt;
	int loopIt = 0;
	double sourceV;

	// resistors vector
	vector<double> resistors;

	// amt input
	cout << "how many resistors do you have?\n";
	cin >> resistorAmt;
	while (!resistorAmt || resistorAmt < 0) { // input val.
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "try again\n";
	    cin >> resistorAmt;
	}

	// resistor value input
	do {
		cout << "enter R" << loopIt + 1 << " in ohms\n";
		cin >> resistor;
		while (!resistor) { // input val.
		    cin.clear();
		    cin.ignore(1000, '\n');
		    cout << "try again\n";
		    cin >> resistor;
		}
		resistors.push_back(resistor);
		loopIt++;
	} while (resistorAmt > loopIt);

	// voltage input
	cout << "enter your source voltage in volts\n";
	cin >> sourceV;
	while (!sourceV || sourceV < 0) { // input val
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "try again\n";
	    cin >> sourceV;
	}	

	cout << "\n";

	// series resistance total resistance output
	double sRT = accumulate(resistors.begin(), resistors.end(), 0);
	cout << "series resistance total: ";
	cout << sRT << " ohms\n";

	// parallel resistance total resistance output
	cout << "parallel resistance total: ";
	if (resistorAmt == 2) {
		cout << serEq(resistors) << " ohms\n";
	} else if (resistorAmt > 2) {
		cout << parEq(resistor, resistors) << " ohms\n\n";
	}

	// voltage drop for series
	cout << "voltage drops in series circuit\n";
	serVEq(resistors, sourceV, sRT);

	// current at Rx for parallel
	cout << "\ncurrent at each resistor in parallel circuit\n";
	parCEq(resistors, sourceV);
}

double parEq(double& resistor, vector<double>& resistors) { // parallel Rt function
	double rec = 0.0;
	int loop = 0;

	while (loop < resistors.size()) {
		rec = rec + (1 / resistors[loop]);
		loop++;
	}

	double total = 1 / rec;
	return total;
}

double serEq(vector<double>& resistors) { // series Rt function
	return ((resistors[0]) * (resistors[1]))/(resistors[0] + resistors[1]);
}

void serVEq(vector<double>& resistors, double sourceV, double sRT) { // voltage drop function
	int loop2 = 0;

	while (loop2 < resistors.size()) {
		double vx = (resistors[loop2]/sRT) * sourceV;
		cout << "R" << loop2 + 1 << " voltage drop: " << vx << "V\n";
		loop2++;
	}
}

void parCEq(vector<double>& resistors, double sourceV) { // current function
	int loop3 = 0;

	while (loop3 < resistors.size()) {
		double ix = (sourceV/resistors[loop3]) * 1000;
		cout << "R" << loop3 + 1 << " current: " << ix << "mA\n";
		loop3++;
	}
}
