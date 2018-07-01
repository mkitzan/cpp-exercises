#include <iostream>
using namespace std;

const double mtrx = 1.0936;
inline double tometer(double yards) { return yards * mtrx; }

int main() {
    double yards;

    do {
        cout << "Enter length in yards: ";
        cin >> yards;
        cout << "Converted to meters: " << tometer(yards) << endl;        
    } while (yards > 0);
    
    return 0;
}
