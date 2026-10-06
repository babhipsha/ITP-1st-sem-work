#include <iostream>
using namespace std;
void CalculateSI(int person) {
    float P, T, R, SI;

    cout << "\nPerson " << person << endl;

    cout << "Enter Principal: ";
    cin >> P;

    cout << "Enter Time: ";
    cin >> T;

    cout << "Enter Rate: ";
    cin >> R;

    SI = (P * T * R) / 100;

    cout << "Simple Interest = " << SI << endl;
}
int main() {
    CalculateSI(1);
    CalculateSI(2);
    CalculateSI(3);

    return 0;
}
