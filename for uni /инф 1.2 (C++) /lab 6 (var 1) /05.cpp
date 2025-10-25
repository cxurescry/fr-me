#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Введите n и k: ";
    cin >> n >> k;

    double* arr = new double[n]; // вещественные числа

    cout << "Введите " << n << " вещественных чисел: ";
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double avg = sum / n;
    int dangerous_count = 0;

    // Проверяем каждый элемент (кроме крайних)
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) { // спад
            if(arr[i] < avg / k) { // опасный спад
                dangerous_count++;
            }
        }
    }

    cout << "Количество опасных спадов: " << dangerous_count << endl;

    delete[] arr;
    return 0;
}
