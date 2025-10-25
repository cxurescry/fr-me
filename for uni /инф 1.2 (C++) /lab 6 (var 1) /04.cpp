#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите N (N >= 3): ";
    cin >> N;

    int* Z = new int[N];

    cout << "Введите " << N << " целых чисел: ";
    for(int i = 0; i < N; i++) {
        cin >> Z[i];
    }

    bool found = false;
    int max_len = 0;
    int start_pos = 0;
    int diff = 0;

    // Перебираем все возможные начальные позиции
    for(int i = 0; i < N - 1; i++) {
        int current_diff = Z[i+1] - Z[i];
        if(current_diff <= 0) continue; // прогрессия должна быть возрастающей

        int len = 2; // текущая длина прогрессии
        int j = i + 2;

        // Проверяем, продолжается ли прогрессия
        while(j < N && Z[j] - Z[j-1] == current_diff) {
            len++;
            j++;
        }

        if(len > max_len) {
            max_len = len;
            start_pos = i;
            diff = current_diff;
            found = true;
        }
    }

    if(found && max_len > 2) {
        cout << "Найдена прогрессия: ";
        for(int i = 0; i < max_len; i++) {
            cout << Z[start_pos + i] << " ";
        }
        cout << endl;
        cout << "Длина: " << max_len << endl;
        cout << "Номер первого элемента: " << start_pos + 1 << endl; // если нумерация с 1
    } else {
        cout << "Возрастающая арифметическая прогрессия длиной более 2 элементов не найдена." << endl;
    }

    delete[] Z;
    return 0;
}
