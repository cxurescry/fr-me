#include <iostream>
using namespace std;

void task3() {
    double x, y;
    cout << "Введите координаты точки: ";
    cin >> x >> y;

    double y1 = x * x - 5;     // нижняя парабола
    double y2 = 2 - 2 * x * x; // верхняя парабола
    double y3 = 1 - x;         // прямая

    bool inE = (x <= -1 && y >= y1 && y <= y3);               // область E
    bool inF = (x >= -1 && x <= 0 && y >= y1 && y <= y3);     // область F
    bool inG = (x >= 0 && x <= 1 && y >= y1 && y <= y2);      // область G
    bool inM = (x >= 0 && x <= 2 && y >= y2 && y <= y3);      // область M
//  bool inN = (x >= 0 && x <= 1 && y <= y3 && y >= y2);      // область N
//  bool inK = (x <= -1 && y <= y3 && y <= y1);               // область K

    if (inE || inF || inM || inG)
        cout << "Точка принадлежит закрашенной области \n";
    else
        cout << "Точка не принадлежит закрашенной области \n";
}

int main() {
    task3();
}
