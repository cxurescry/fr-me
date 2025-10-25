#include <iostream>
using namespace std;

int main() {
    int n1, m1, n2, m2;
    cout << "Введите размерности первой матрицы (n1 x m1): ";
    cin >> n1 >> m1;
    cout << "Введите размерности второй матрицы (n2 x m2): ";
    cin >> n2 >> m2;

    if(m1 != n2) {
        cout << "Умножение невозможно: количество столбцов первой матрицы (" << m1
             << ") не равно количеству строк второй матрицы (" << n2 << ")." << endl;
        return 0;
    }

    // Создание матриц
    int** A = new int*[n1];
    int** B = new int*[n2];
    int** C = new int*[n1];

    for(int i = 0; i < n1; i++) {
        A[i] = new int[m1];
        C[i] = new int[m2];
    }
    for(int i = 0; i < n2; i++) {
        B[i] = new int[m2];
    }

    // Ввод матриц
    cout << "Введите элементы матрицы A:" << endl;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Введите элементы матрицы B:" << endl;
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < m2; j++) {
            cin >> B[i][j];
        }
    }

    // Умножение матриц
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < m1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Вывод результата
    cout << "Результат умножения A * B:" << endl;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m2; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождение памяти
    for(int i = 0; i < n1; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    for(int i = 0; i < n2; i++) {
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
