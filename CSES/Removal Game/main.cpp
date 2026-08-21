#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353
ll dp[5001][5001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int>x(n);
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
        sum+=x[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int l = 0; l+i < n; l++)
        {
            dp[l][l+i] = max(x[l]-dp[l+1][l+i], x[l+i]-dp[l][l+i-1]);
        }
    }

    cout<<(dp[0][n-1]+sum)/2<<endl;

    return 0;
}