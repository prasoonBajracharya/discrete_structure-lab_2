#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the dimension n for the square matrices: ";
    cin >> n;
    int A[100][100], B[100][100], joinMatrix[100][100], meetMatrix[100][100], boolProduct[100][100];
    int i, j, k;
    cout << "Enter the elements for matrix A (each element should be 0 or 1):\n";
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            cin >> A[i][j];
        }
    }
    cout << "Enter the elements for matrix B (each element should be 0 or 1):\n";
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            cin >> B[i][j];
        }
    }
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            joinMatrix[i][j] = (A[i][j] || B[i][j]) ? 1 : 0;
        }
    }
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            meetMatrix[i][j] = (A[i][j] && B[i][j]) ? 1 : 0;
        }
    }
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            boolProduct[i][j] = 0;
            for (k = 0; k < n; k = k + 1) {
                if (A[i][k] && B[k][j]) {
                    boolProduct[i][j] = 1;
                    break;
                }
            }
        }
    }
    cout << "\nJoin (element-wise OR):\n";
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            cout << joinMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nMeet (element-wise AND):\n";
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            cout << meetMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nBoolean Product:\n";
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < n; j = j + 1) {
            cout << boolProduct[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
