#include <iostream>
using namespace std;

void transposeMatrix(int mat[10][10], int trans[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans[j][i] = mat[i][j];
}

int main() {
    int mat[10][10], trans[10][10], rows, cols;

    cout << "Enter rows and columns of the matrix: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];

    transposeMatrix(mat, trans, rows, cols);

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
