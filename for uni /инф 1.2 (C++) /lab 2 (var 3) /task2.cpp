#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cout << "Введите X и Y: ";
  double x, y; cin >> x >> y;
  if (x > 0 && x + y > 3) {
    cout << log(sqrt(x + y) - 1) << endl;
  }
  else if (x + y < 0) {
    cout << (x - y + log(-1 / (x + y))) / (x + y) << endl;
  }
  else {
    cout << pow(M_E, x - y) << endl;
  }
  return 0;
}
