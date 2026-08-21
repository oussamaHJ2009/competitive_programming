#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if(a[i] == 7 - a[i + 1] || a[i] == a[i + 1]){
                ans++;
                i++;
            }
        }
        cout<< ans << endl;
    }
    
    return 0;
}