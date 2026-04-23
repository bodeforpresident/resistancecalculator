#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

double parEq(double& resistor, vector<double>& resistors, vector<double>& resistorsOver2);
double serEq(vector<double>& resistors);

int main() {
    double resistor;
    int resistorAmt;
    int loopIt = 0;
    
    vector<double> resistors;
    vector<double> resistorsOver2;
    
    cout << "how many resistors do you have?\n";
    cin >> resistorAmt;
    
    do {
        cout << "enter R" << loopIt + 1 << "\n";
        cin >> resistor;
        resistors.push_back(resistor);
        loopIt++;
    } while (resistorAmt > loopIt);
    
    cout << "\n";
    
    double sRT = accumulate(resistors.begin(), resistors.end(), 0);
    cout << "series resistance total: ";
    cout << sRT << "\n";
    
    cout << "parallel resistance total: ";
    if (resistorAmt == 2) {
        cout << serEq(resistors) << " ohms\n";
    } else if (resistorAmt > 2) {
        cout << parEq(resistor, resistors, resistorsOver2) << " ohms\n";
    }
}

double parEq(double& resistor, vector<double>& resistors, vector<double>& resistorsOver2) {
    double rec = 0.0;
    int loop = 0;
        
    while (loop < resistors.size()) {
        rec = rec + (1 / resistors[loop]);
        loop++;
    }
    
    double total = 1 / rec;
    return total;  
}

double serEq(vector<double>& resistors) {
    return ((resistors[0]) * (resistors[1]))/(resistors[0] + resistors[1]);
}
