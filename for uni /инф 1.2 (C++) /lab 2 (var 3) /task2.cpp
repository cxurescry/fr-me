#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x, y; cin >> x >> y;
  if (x > 0 && x + y > 3) {
    cout << log(sqrt(x + y) - 1);
  }
  else if (x + y < 0) {
    cout << (x - y + log(-1 / (x + y))) / (x + y);
  }
  else {
    pow(M_E, x - y);
  }
  return 0;
}
