#include <iostream>
#include <cmath>
using namespace std;

// function declarations
void tSR();
void tPR();

int main() {
    tSR();
    tPR();
}

// function definitions
void tSR() {
    double seriesR1, seriesR2;
    
    cout << "Enter your first resistor value (in Ohms): ";
    cin >> seriesR1;
    cout << "Enter your second resistor value (in Ohms): ";
    cin >> seriesR2;

    double tRSeries = seriesR1 + seriesR2;
    cout << "Your total resistance is " << tRSeries << " Ohms\n";
    
    double sourceSeriesV;
    cout << "Enter your source voltage (in volts): ";
    cin >> sourceSeriesV;
    
    double vS1 = (seriesR1/tRSeries) * sourceSeriesV;
    double vS2 = (seriesR2/tRSeries) * sourceSeriesV;
    cout << "The voltage drop at resistor one is " << vS1 << "v. The voltage drop at resistor two is " << vS2 << "v\n";
}

void tPR() {
    double parallelR1, parallelR2;
    
    cout << "Enter your first resistor value (in Ohms): ";
    cin >> parallelR1;
    cout << "Enter your second resistor value (in Ohms): ";
    cin >> parallelR2;

    double tRParallel = (parallelR1 * parallelR2)/(parallelR1 + parallelR2);    
    cout << "Your total resistance is " << tRParallel << " Ohms\n";
    
    double sourceParV;
    cout << "Enter your source voltage (in volts): ";
    cin >> sourceParV;
    
    double iP1 = (parallelR1/tRParallel) * sourceParV;
    double iP2 = (parallelR2/tRParallel) * sourceParV;
    cout << "The current at resistor one is " << iP1 << "mA. The current at resistor two is " << iP2 << "mA\n";    
}

void vDS() {
    
}
