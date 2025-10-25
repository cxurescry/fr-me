#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Введите n и k (0 < k < n): ";
    cin >> n >> k;

    int* arr = new int[n]; // динамический массив

    cout << "Введите " << n << " целых чисел: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Циклический сдвиг вправо на k позиций
    int* temp = new int[k]; // временный массив для последних k элементов
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Сдвиг остальных элементов вправо
    for(int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Копирование временного массива в начало
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    cout << "Массив после сдвига: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] temp;

    return 0;
}
