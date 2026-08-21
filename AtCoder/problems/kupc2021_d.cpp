#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,K;
    cin>>N>>K;
    vector<int>A(K);
    for(int i=0;i<K;i++)cin>>A[i];
    
    vector<int>dp(N+1);
    for (int i =0; i <= N; i++)
    {
        for (auto a:A)
        {
            if(a<=i)dp[i]=max(i-dp[i-a],dp[i]);
        }
        
    }
    cout<<dp[N];

    return 0;

}