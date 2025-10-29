#include <iostream>
using namespace std;

int main() {
    cout << "Введите свои баллы: ";
    int n; cin >> n;
    if (n < 0 && n < 55) {
        cout << "Неудовлетворительно" << "\n";
    }
    if (n >= 55 && n < 70) {
        cout << "Удовлетворительно" << "\n";
    }
    if (n >= 70 && n < 90) {
        cout << "Хорошо" << "\n";
    }
    if (n >= 90 && n <= 100) {
        cout << "Отлично" << "\n";
    }
    if (n < 0 && n > 100) {
         cout << "Ошибка" << "\n";
    }
    return 0;
}
