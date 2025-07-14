#include <iostream>
using namespace std;

int GCD(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int eGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int gcd = eGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Euclidean GCD: " << GCD(a, b) << endl;

    int x, y;
    int gcd = eGCD(a, b, x, y);
    cout << "Extended Euclidean GCD: " << gcd << endl;
    cout << "Coefficients x and y such that ax + by = gcd: ";
    cout << x << " " << y << endl;

    return 0;
}
