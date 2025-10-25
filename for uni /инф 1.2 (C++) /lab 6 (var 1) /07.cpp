#include <iostream>
using namespace std; 

int main() {
    int N, M;
    cout << "Введите N и M: ";
    cin >> N >> M;

    int** Z = new int*[N];
    for(int i = 0; i < N; i++) {
        Z[i] = new int[M];
    }

    cout << "Введите элементы матрицы Z(" << N << "x" << M << "):" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Z[i][j];
        }
    }

    int* B = new int[N]; // массив результатов
    int K = 0; // количество строк, удовлетворяющих условию

    for(int i = 0; i < N; i++) {
        bool has_negative = false;
        for(int j = 0; j < M; j++) {
            if(Z[i][j] < 0) {
                has_negative = true;
                break;
            }
        }

        if(has_negative) {
            int sum = 0;
            int count = 0;
            for(int j = 0; j < M; j++) {
                // Исключаем диагональный элемент (если есть) и нули
                if(j != i && Z[i][j] != 0) { // j != i — проверка диагонали
                    sum += Z[i][j];
                    count++;
                }
            }
            if(count > 0) {
                B[K++] = sum / count; // целочисленное деление
            } else {
                B[K++] = 0; // или можно пропустить, но по условию заполняем B(K)
            }
        }
    }

    cout << "Массив B (K=" << K << "): ";
    for(int i = 0; i < K; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Освобождение памяти
    for(int i = 0; i < N; i++) {
        delete[] Z[i];
    }
    delete[] Z;
    delete[] B;

    return 0;
}
