#include <iostream>
using namespace std;

typedef long long ll;

void solveE() {
    ll l, r;
    cin >> l >> r;
    
    if (2 * l <= r) {
        cout << l << " " << 2 * l << endl;
    } else {
        cout << -1 << " " << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solveE();
    }
    
    return 0;
}
