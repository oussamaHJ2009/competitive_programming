#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> l(m), r(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j+i <= n; j++)
        {
            
        }
        
    }
    
    
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        
    }

    return 0;
}