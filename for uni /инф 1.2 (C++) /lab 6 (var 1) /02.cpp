#include <iostream>
using namespace std;

int main() {
    const int N = 10; // можно сделать вводимой константой
    int Z[N];

    cout << "Введите " << N << " чисел: ";
    for(int i = 0; i < N; i++) {
        cin >> Z[i];
    }

    // Подсчет положительных и чисел в интервале [-7;5]
    int positive_count = 0;
    int in_interval_count = 0;

    for(int i = 0; i < N; i++) {
        if(Z[i] > 0) positive_count++;
        if(Z[i] >= -7 && Z[i] <= 5) in_interval_count++;
    }

    cout << "Количество положительных чисел: " << positive_count << endl;
    cout << "Чисел в интервале [-7;5]: " << in_interval_count << endl;

    // Подсчет отрицательных чисел для создания массива P
    int negative_count = 0;
    for(int i = 0; i < N; i++) {
        if(Z[i] < 0) negative_count++;
    }

    if(negative_count == 0) {
        cout << "Отрицательных чисел нет. Массив P не создан." << endl;
    } else {
        int* P = new int[negative_count]; // динамический массив
        int p_index = 0;
        for(int i = 0; i < N; i++) {
            if(Z[i] < 0) {
                P[p_index++] = Z[i];
            }
        }

        cout << "Массив P (отрицательные числа): ";
        for(int i = 0; i < negative_count; i++) {
            cout << P[i] << " ";
        }
        cout << endl;

        delete[] P; // освобождаем память
    }

    return 0;
}
