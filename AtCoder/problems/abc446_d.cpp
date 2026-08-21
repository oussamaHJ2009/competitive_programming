#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &it:A)cin>>it;
    map<int,int>dp;
    int ans=0;
    for (auto x:A)
    {
        dp[x]=max(dp[x-1]+1,1);
        ans=max(dp[x],ans);
    }
    cout<<ans;
    

    return 0;

}