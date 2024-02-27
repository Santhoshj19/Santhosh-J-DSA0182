#include <iostream>

using namespace std;

int main() {
    int dividend, divisor, quotient;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    if (divisor != 0) {
        quotient = dividend / divisor;
        cout << "Quotient: " << quotient << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }

    return 0;
}