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
        vector<int> a(n + 1);
        vector<int> f(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            cin>>f[i];
        }
        
        for (int i = 2; i < n; i++)
        {
            a[i] = f[i + 1] + f[i - 1] - 2*f[i]; 
        }
        
        
    }
    
    return 0;
}