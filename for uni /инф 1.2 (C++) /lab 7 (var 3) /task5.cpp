#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    cout << "Введите N (>= 3): ";
    int n;
    if (!(cin >> n) || n < 3) {
        cout << "N должно быть >= 3\n";
        return 1;
    }

    vector<int> S(n);

    // генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 20);

    // заполнение массива и сортировка
    for (int i = 0; i < n; ++i) {
        S[i] = dist(gen);
    }
    sort(S.begin(), S.end());

    // вывод массива
    cout << "Массив S(n): [ ";
    for (int v : S) cout << v << " ";
    cout << "]" << endl;

    cout << "Введите x: ";
    int x;
    cin >> x;

    // находим диапазон всех элементов, равных x
    auto range = equal_range(S.begin(), S.end(), x);

    if (range.first == range.second) {
        cout << "Такого элемента нет." << endl;
    } else {
        int countOfElement = static_cast<int>(range.second - range.first);
        cout << "Кол-во заданного элемента x: " << countOfElement << endl;
        cout << "Их позиции: ";
        // выводим индексы (0-based) в порядке возрастания
        for (auto it = range.first; it != range.second; ++it) {
            cout << (it - S.begin()) << " ";
        }
        cout << endl;
    }

    return 0;


    }
