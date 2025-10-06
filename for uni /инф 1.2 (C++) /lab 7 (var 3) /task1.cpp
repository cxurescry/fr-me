#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    // инициализация числа n и массива Z(n)
    cout << "Введите N (>= 3): " << endl;
    int n; cin >> n;
    vector <int> Z(n);

    random_device rd; // создает объект, представляющий "истинное" случайное число на основе аппаратного источника энтропии (1)
    mt19937_64 gen(rd()); // Создаёт генератор случайных чисел типа Mersenne Twister 19937 и инициализирует его числом из rd().
    uniform_int_distribution<> dist(0, 20);
    // Определяет распределение случайных чисел — в данном случае равномерное целочисленное распределение от 0 до 20 включительно.

    // заполнение и вывод массива
    cout << "Массив Z(n): " << "[ ";
    for (int i = 0; i < n; i++) {
        int el = dist(gen);
        Z[i] = el;
        cout << Z[i] << " ";
    }
    cout << "]" << endl;

    cout << "Введите x: ";
    int x; cin >> x;
    int count = 0;

    vector <int> data;
    for (int i = 0; i < n; i++) {
        if (Z[i] == x) {
            count++;
            data.push_back(i);
        }
    }

    if (count == 0) {
        cout << "Таких элементов нет.";
    } else {
        cout << "Количество элементов, равных x в массиве Z(n): " << count << endl;
        cout << "Их позиции: ";
        for (auto elem : data) cout << elem << " ";
        cout << endl;
    }

}

/*
(1) - устройство или механизм внутри компьютера, который умеет выдавать непредсказуемые случайные биты данных.
*/
