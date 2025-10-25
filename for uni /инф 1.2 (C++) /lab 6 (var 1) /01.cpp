#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Введите a и b: ";
    cin >> a >> b;

    int* ptr_a = &a; // указатель на a
    int* ptr_b = &b; // указатель на b

    // Найти минимальное значение через указатели
    if (*ptr_a < *ptr_b) {
        *ptr_a *= 2; // увеличить a в 2 раза
    } else {
        *ptr_b *= 2; // увеличить b в 2 раза
    }

    // Поменять местами значения через указатели
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;

    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
