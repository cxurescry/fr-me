#include <bits/stdc++.h>
using namespace std;

void solveD() {
    int n, t; cin >> n >> t;
    vector <int> vi;
    int time;
    while (n--) {
		cin >> time;
		vi.push_back(time);
	  }
    sort(vi.begin(), vi.end());
    
	// for (int i = 0; i != vi.size(); i++) {cout << vi[i] << " ";}
	// cout << "\n";
	    
    int remainTime = t;
    int ans = 0; int curIndex = 0; 
    while ( remainTime >= 0 || curIndex != (n - 1) ) {
        if (remainTime - vi[curIndex] < 0)
            break;
        else {
        	// cout << remainTime << " " << vi[curIndex];
        	// cout << "\n";
        	
            remainTime -= vi[curIndex];
            curIndex++;
            ++ans;
        }
        // cout << "curIndex & curAns: " << curIndex << " & " << ans << "\n";  
    }
    cout << ans << "\n";
}

int main() {
    solveD();
    return 0;
}
