#include<iostream>
using namespace std;

int main() {
    int bin1[4], bin2[4], sum[5], carry = 0;
    int product[8];
    int i, j;

    for (i = 0; i < 8; i = i + 1) {
        product[i] = 0;
    }

    cout << "Enter first 4-bit binary number (one bit at a time):\n";
    for (i = 0; i < 4; i = i + 1) {
        cout << "bit " << i << ": ";
        cin >> bin1[i];
    }

    cout << "Enter second 4-bit binary number (one bit at a time):\n";
    for (i = 0; i < 4; i = i + 1) {
        cout << "bit " << i << ": ";
        cin >> bin2[i];
    }

    for (i = 3; i >= 0; i = i - 1) {
        int s = bin1[i] + bin2[i] + carry;
        if (s == 0) {
            sum[i + 1] = 0;
            carry = 0;
        } else if (s == 1) {
            sum[i + 1] = 1;
            carry = 0;
        } else if (s == 2) {
            sum[i + 1] = 0;
            carry = 1;
        } else {
            sum[i + 1] = 1;
            carry = 1;
        }
    }
    sum[0] = carry;

    for (i = 3; i >= 0; i = i - 1) {
        if (bin2[i] == 1) {
            int carry_mul = 0;
            for (j = 3; j >= 0; j = j - 1) {
                int index = i + j + 1;
                int p = bin1[j] + product[index] + carry_mul;
                if (p == 0 || p == 1) {
                    product[index] = p;
                    carry_mul = 0;
                } else {
                    product[index] = p % 2;
                    carry_mul = p / 2;
                }
            }
            if (i + j + 1 >= 0) {
                product[i + j + 1] = carry_mul;
            }
        }
    }

    cout << "Sum: ";
    for (i = 0; i < 5; i = i + 1) {
        cout << sum[i];
    }
    cout << endl;

    cout << "Product: ";
    for (i = 0; i < 8; i = i + 1) {
        cout << product[i];
    }

    return 0;
}
