#include <iostream>
using namespace std;

int main() {
    cout << "Введите свои баллы: ";
    int n; cin >> n;
    if (n < 0 && n < 55) {
        cout << "Неудовлетворительно";
    }
    if (n >= 55 && n < 70) {
        cout << "Удовлетворительно";
    }
    if (n >= 70 && n < 90) {
        cout << "Хорошо";
    }
    if (n >= 90 && n <= 100) {
        cout << "Отлично";
    }
    if (n < 0 && n > 100) {
         cout << "Ошибка";
    }
    return 0;
}
