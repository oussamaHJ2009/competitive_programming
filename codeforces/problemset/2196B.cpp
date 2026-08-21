#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        vector<int> dp(n + 1);
        //useless dp btw
        for (int j = 1; j <= n; j++)
        {
            dp[j] = dp[j - 1];
            int i = j - a[j];
            while (i > 0)
            {
                if((j - i)/a[j] == a[i]) dp[j]++;
                i -= a[j];
            }
            
            
        }
        cout<<dp[n]<<endl;
    }
    
    return 0;
}