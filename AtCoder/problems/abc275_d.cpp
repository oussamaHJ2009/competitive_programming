#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

ll N;
map<ll,ll>dp;
map<ll,bool>used;
ll f(ll n){
    if(!used[n]) {
        dp[n]=f(n/2ll)+f(n/3ll);
        used[n]=true;
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>N;
    dp[0]=1;
    used[0]=true;
    cout<<f(N);
    return 0;

}