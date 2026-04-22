#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

void parEq(double& resistor, vector<int>& resistors, vector<int>& resistorsOver2);

int main() {
    double resistor;
    int resistorAmt;
    int loopIt = 0;
    
    vector<int> resistors;
    vector<int> resistorsOver2;
    
    cin >> resistorAmt;
    
    do {
        cin >> resistor;
        resistors.push_back(resistor);
        loopIt++;
    } while (resistorAmt > loopIt);
    
    double sRT = accumulate(resistors.begin(), resistors.end(), 0);
    cout << sRT << "\n";
    
    if (resistorAmt == 2) {
        double pRT = ((resistors[0]) * (resistors[1]))/(resistors[0] + resistors[1]);
        cout << pRT;
    } else if (resistorAmt > 2) {
        int rec = 0;
    
        for (int i = 0; i < resistors.size(); i++) {
            rec = (1 / resistors[i]);
            resistorsOver2.push_back(rec);
        }
    
        double total = (1 / accumulate(resistorsOver2.begin(), resistorsOver2.end(), 0));
        cout << total << "\n";
    }
}

void parEq(double& resistor, vector<int>& resistors, vector<int>& resistorsOver2) {
}
