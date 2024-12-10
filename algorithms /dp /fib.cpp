#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector <int> arr(n + 1);
    if (n == 0) cout << 0;
    else {
        arr[1] = 1;
        for (int i = 2; i != n + 1; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }
    cout << arr[n];
}
