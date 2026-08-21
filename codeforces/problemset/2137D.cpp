#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; 
    cin >> t;  // Number of test cases
    while (t--) {
        int n; 
        cin >> n;  // Size of the array
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // Input the elements of the array
        }
        
        vector<vector<int>> FRQ(n + 1);  // Frequency list
        for (int i = 0; i < n; i++) {
            FRQ[a[i]].push_back(i);  // Store indices of each value
        }
        
        vector<int> b(n, 0);  // Result array
        int cnt = 1;
        bool possible = true;
        
        for (int i = 1; i <= n; i++) {
            if (FRQ[i].size() % i != 0) {
                possible = false;  // Not possible to segment
                cout << -1 << endl;
                break;
            } 
            else {
                int c = 0;
                while (c < FRQ[i].size()) {
                    for (int v = 0; v < i; v++) {
                        b[FRQ[i][c]] = cnt;  // Assign the counter value
                        c++;
                    }
                    cnt++;
                }
            }
        }
        
        if (possible) {
            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";  // Print the result array
            }
            cout << endl;
        }
    }
    
    return 0;
}
