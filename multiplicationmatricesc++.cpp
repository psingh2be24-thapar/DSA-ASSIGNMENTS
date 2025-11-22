#include <iostream>
using namespace std;

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns for matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible.\n";
        return 0;
    }

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    multiplyMatrices(a, b, result, r1, c1, r2, c2);

    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
