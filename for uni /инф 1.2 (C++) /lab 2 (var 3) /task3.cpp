#include <iostream>
using namespace std;

int main() {
  cout << "Введите координаты точки (X/Y)";
  double x, y; // координаты точки
  cin >> x >> y;

  // парабола 1 (с ветвями вверх)
  double y1 = x * x - 5;
  // парабола 2 (с ветвями вниз)
  double y2 = -2 * x * x + 2;
  // прямая
  double y3 = -x + 1;

  if (y >= y1 && y <= y2 && y <= y3) {
    cout << "Точка принадлежит закрашенной области";
  } else
    cout << "Точка не принадлежит закрашенной области";
}
