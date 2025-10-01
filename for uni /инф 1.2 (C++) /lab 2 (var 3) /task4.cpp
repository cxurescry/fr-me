#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x; cin >> x;
    double term, approximation; // слагаемое, сумма ряда
    approximation = 0.0;
    int n = 1; // знаменатель
    
    do {
        term = pow(x, n) / n;
        if (n % 2 != 0) 
            approximation += term;
        else {
            approximation -= term;
        }
        n++;
    } while (fabs(term) > 1e-7);
    
    cout << "Приблмжённое значение функции: " << approximation << endl;
    cout << "Точное значение: " << log(1 + x) << endl;
}
