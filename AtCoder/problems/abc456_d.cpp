#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string S;
    cin>>S;
    map<char,ll>dp;
    dp['a']=0;
    dp['b']=0;
    dp['c']=0;
    for (auto c:S)
    {
        dp[c]=(dp['a']+dp['b']+dp['c']+1)%mod;
    }
    cout<<(dp['a'] + dp['b'] + dp['c'])%mod;

    return 0;

}