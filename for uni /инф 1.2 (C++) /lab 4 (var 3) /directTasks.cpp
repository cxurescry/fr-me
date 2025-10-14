#include <iostream>
#include <iomanip>
using namespace std;

void task1() {
    unsigned int n, result;
    cout << "Please enter an integer: ";
    cin >> n;
    result = 1 << n; // сдвигаем все бмты числа влево на n позиций (принцип работы - (1))
    cout << "Decinal: " << result << endl;
    cout << "Octal: " << oct << result << endl;
    cout << "Hex: " << hex << result << endl;
    // * oct и hex - манипуляторы из iostream для перевода числа из 10-СС в 8-СС и 16-СС соответственно
}

void task2() {
    unsigned int X, n;
    cin >> X >> n;

    unsigned int mask = 1U << n;
    unsigned int bit = (X >> n) & 1;

    if (bit != 0) {
        cout << "Bit " << bit << " is 1" << endl;
    } else {
        cout << "Bit " << bit << " is 0" << endl;
    }
}


void task3() {
    unsigned int X, n;
    cout << "Enter X and bit number n: ";
    cin >> X >> n;

    unsigned int mask = 1U << n;
    X = X | mask;

    cout << "Result in decimal: " << X << endl;
    cout << "Result in octal: " << oct << X << endl;
    cout << "Result in hexadecimal: " << hex << X << endl;
}

void task4() {
    unsigned int X, n;
    cout << "Enter X and bit number n: ";
    cin >> X >> n;
    unsigned int mask = 1U << n;
    X = X & (~mask);

    cout << "Result in decinal: " << X << endl;
    cout << "Result in octal: " << oct << X << endl;
    cout << "Result in hexadecimal: " << hex << X << endl;
}

void task5() {
    unsigned int X, n;
    cin >> X >> n;

    unsigned int mask = 1U << n;
    X = X ^ mask;

    cout << "Decimal: " << X << endl;
    cout << "Octal: " << oct << X << endl;
    cout << "Hex: " << hex << X << endl;
}

void task6() {
    unsigned int X, Y, M;
    cin >> X >> Y >> M;

    unsigned int mask = (1U << M) - 1; // маска для M битов
    X = (X & ~mask) | (Y & mask);      // замена

    // Выводим X и Y в двоичном виде (как в задании)
    cout << "Y in binary: ";
    for (int i = 31; i >= 0; --i) {
        cout << ((Y >> i) & 1);
    }
    cout << endl;

    cout << "Resulting X in binary: ";
    for (int i = 31; i >= 0; --i) {
        cout << ((X >> i) & 1);
    }
    cout << endl;
}


int main() {
    task6();
    return 0;
}


/*
(1) - рассмотрим некоторые числа в двоичной СС
1 = 1
2 = 10
4 = 100
8 = 1000
16 = 10000 и т.д
заметим, что умножение числа на 2 добавлят ноль справа, сдвиг числа на n позиций тоже добавляет n нулей, ->
умножает число 2 n раз
1 << n <=> 001 << n, т.е "001" + ((n - 1) * "0")
Пример:
1 << 2 = 10
1 << 3 = 100
1 << 4 = 1000
 */
