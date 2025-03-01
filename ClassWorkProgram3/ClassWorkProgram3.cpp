/* Ќапишите программу, котора€ принимает на вход матрицу (двемерный массив), умножает ее на скал€р и выводит результат */

#include <iostream>

using namespace std;

int** createMatrix(int rows, int cols);
void deleteMatrix(int** matrix, int rows);
void multiplyMatrix(int** matrix, int rows, int cols, int scalar);

int main()
{
    setlocale(LC_ALL, "rU");

    int rows = 2;
    int cols = 2;
    int scalar = 2;

    int** matrix = createMatrix(rows, cols);

    cout << "¬ведите элементы матрицы: " << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cin >> matrix[i][j];
        }
    }

    multiplyMatrix(matrix, rows, cols, scalar);

    cout << "–езультат умножени€ матрицы на скал€р " << scalar << ": " << endl;
    for (int l = 0; l < rows; l++) {
        for (int k = 0; k < rows; k++) {
            cout << matrix[l][k];
        }
        cout << endl;
    }

    deleteMatrix(matrix, rows);

    return 0;
}

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void multiplyMatrix(int** matrix, int rows, int cols, int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}