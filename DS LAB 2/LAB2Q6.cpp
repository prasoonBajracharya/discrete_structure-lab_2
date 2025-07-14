#include <iostream>
using namespace std;

int GCDE(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = GCDE(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = GCDE(a, m, x, y);
    if(g != 1)
        return -1;
    if(x < 0)
        x += m;
    return x;
}

int main() {
    int n;
    cout << "Enter the number of congruences (max 10): ";
    cin >> n;
    const int MAX = 10;
    if(n > MAX) {
        cout << "Maximum allowed congruences is " << MAX;
        return 1;
    }
    int mod[MAX], rem[MAX];
    for (int i = 0; i < n; i = i + 1) {
        cout << "For congruence " << (i + 1) << ", enter modulus: ";
        cin >> mod[i];
        cout << "Enter remainder: ";
        cin >> rem[i];
    }
    int M = 1;
    for (int i = 0; i < n; i = i + 1)
        M *= mod[i];
    int result = 0;
    for (int i = 0; i < n; i = i + 1) {
        int Mi = M / mod[i];
        int inv = modInverse(Mi, mod[i]);
        if (inv == -1) {
            cout << "Error: Inverse does not exist. Check that moduli are pairwise coprime.";
            return 1;
        }
        result += rem[i] * Mi * inv;
    }
    result %= M;
    if (result < 0)
        result += M;
    cout << "The solution is x = " << result << " modulo " << M;
    return 0;
}
