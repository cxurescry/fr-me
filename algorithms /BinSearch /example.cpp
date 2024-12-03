#include <bits/stdc++.h>
using namespace std;

int binS(vector <int> data, int target) {
    sort(begin(data), end(data));
    int left = 0, right = data.size();
    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] == target)
            return mid;
        if (data[mid] > target)
            right = mid - 1;
        else 
            left = mid + 1;
    return -1; // if target not found
    }
}

int main() {
  // test case:
  vector <int> data = {1, 432, 34, 99, 999, 8, 16, 3}
  int target = 99;
  cout << binS(data, target) << "\n";
}
