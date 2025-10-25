#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Введите n и m (n*m < 100): ";
    cin >> n >> m;

    int** A = new int*[n];
    for(int i = 0; i < n; i++) {
        A[i] = new int[m];
    }

    int num = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) { // чётная строка — слева направо
            for(int j = 0; j < m; j++) {
                A[i][j] = num++;
            }
        } else { // нечётная строка — справа налево
            for(int j = m - 1; j >= 0; j--) {
                A[i][j] = num++;
            }
        }
    }

    cout << "Матрица змейкой:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождение памяти
    for(int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
