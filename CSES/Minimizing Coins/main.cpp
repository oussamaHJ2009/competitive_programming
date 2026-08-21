#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,X;
    cin>>N>>X;
    vector<int>C(N);
    for (int i = 0; i < N; i++)
    {
        cin>>C[i];
    }
    vector<int>dp(X+1,1e6+1);
    dp[0]=0;
    for (int i = 1; i <= X; i++)
    {
        for (auto c:C)
        {
            if(i-c>=0)dp[i]=min(dp[i-c]+1,dp[i]);
        }
    }
    cout<<(dp[X]!=1e6+1 ? dp[X] : -1)<<endl;

    return 0;

}