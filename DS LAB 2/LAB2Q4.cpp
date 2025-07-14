#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Prime factors: ";
    for (int i = 2; i * i <= n; i = i + 1) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1) {
        cout << n;
    }
    return 0;
}
