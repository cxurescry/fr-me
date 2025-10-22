#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// перевод числа из десятичной в любую СС
string toBase(unsigned int x, unsigned int base) {
    string digits = "0123456789ABCDEFGHIJK";
    string result;
    while (x) {
        result += digits[x % base];
        x /= base;
    }
    reverse(begin(result), end(result));
    return result;
}

// Преобразует символ в число
int charToDigit(char c) {
    if (isdigit(c))
        return c - '0';
    return toupper(c) - 'A' + 10;
}

// Преобразует число в символ
char digitToChar(int d) {
    if (d < 10)
        return '0' + d;
    return 'A' + (d - 10);
}

// 1. Вывести представление числа r - ой СС
void task1() {
    cout << "Введите основание системы счисления p (2 <= p <= 16): ";
    unsigned int p; cin >> p;
    if (p < 2 || p > 16) cout << "Вы неверно ввели основание СС.";

    cout << "Введите положительное число N: ";
    unsigned int n; cin >> n;
    cout << endl;

    cout << toBase(n, p) << endl;
}

// 2. перевести в десятичную СС по схеме Горнера
void task2() {
    cout << "Введите основание системы счисления p (2 <= p <= 16): ";
    unsigned int p; cin >> p;
    if (p < 2 || p > 16) cout << "Вы неверно ввели основание СС.";

    string num; cin >> num;

    int result;

    for (char c : num) {
        int digit;
        if (isdigit(c)) {
            digit = c - '0';
            // например, в ASCII таблице '2' имеет код 50
            // чтобы достать его числовое значение, 
            // нужно от данного кода отнять начальный код для чисел ('0' имеет код 48, '2' - '0' = 50 - 48 = 2)
        }
        else {
            digit = toupper(c) - 'A' + 10;
        }
        result = result * p + digit;
    }
    cout << num << "(" << p << ") = " << result << "(10)" << endl;
}

// 3. перевести числа M и N в p-СС и сложить м-у собой
void task3() {
    cout << "Введите основание системы счисления p (2 <= p <= 16): ";
    unsigned int p; cin >> p;
    if (p < 2 || p > 16) cout << "Вы неверно ввели основание СС.";

    unsigned int m, n; cin >> m >> n;
    string digits = "0123456789ABCDEFGHIJK";
    string res1, res2;

    res1 = toBase(m, p);
    res2 = toBase(n, p);

    // Выравниваем длины
    while (res1.size() < res2.size()) res1 = "0" + res1;
    while (res2.size() < res1.size()) res2 = "0" + res2;

    string result = "";
    int carry = 0;

    cout << "\nПошаговое сложение в столбик:\n";

    // Сложение справа налево
    for (int i = res1.size() - 1; i >= 0; i--) {
        int da = charToDigit(res1[i]);
        int db = charToDigit(res2[i]);

        int sum = da + db + carry;
        int digit = sum % p;
        carry = sum / p;

        cout << res1[i] << " + " << res2[i]
             << " + перенос " << carry
             << " => цифра " << digitToChar(digit)
             << " (перенос " << carry << ")\n";

        result = digitToChar(digit) + result;
    }

    if (carry > 0)
        result = digitToChar(carry) + result;

    cout << "\nРезультат: " << res1 << "(" << p << ") + " << res2
         << "(" << p << ") = " << result << "(" << p << ")\n";

}

int main() {
    task1();
    task2();
    task3();
    return 0;
}
