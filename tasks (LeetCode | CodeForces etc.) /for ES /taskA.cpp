#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solveA() {
    int t; cin >> t;
    int ans;
    while (t--) {
        int n; cin >> n;
        ans = n % 4 == 0 ? n / 4 : (n / 4) + 1 // т.к n - чётное, то остаток при делении на 4 всегда равен либо 0, либо 2, если 2, то достаточно одной курицы
        cout << ans << "\n";
    }
}

int main() {
    solveA();
    return 0;
}
