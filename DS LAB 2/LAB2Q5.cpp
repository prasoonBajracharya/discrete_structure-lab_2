#include <iostream>
using namespace std;
int main() {
    int seed, a, c, m, count;
    cout << "Enter seed value: ";
    cin >> seed;
    cout << "Enter multiplier (a): ";
    cin >> a;
    cout << "Enter increment (c): ";
    cin >> c;
    cout << "Enter modulus (m): ";
    cin >> m;
    cout << "Enter number of random numbers to generate: ";
    cin >> count;
    int x = seed;
    cout << "Generated random numbers:" << endl;
    for (int i = 0; i < count; i = i + 1) {
        x = (a * x + c) % m;
        cout << x << " ";
    }
    return 0;
}
