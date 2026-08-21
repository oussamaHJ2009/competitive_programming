#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool pal(ll n,int l){
    for (int i = 0; i < l/2; i++)
    {
        int b1 = (n>>i)&1;
        int b2 = (n>>(l-1-i))&1;
        if(b1!=b2)return false;
    }
    if(l&1 && ((n>>(l/2))&1) !=0)return false;
    return true;
}

void solve() {
    ll n;
    cin>>n;
    if(n==0){
        cout<<"YES\n";
        return;
    }
    int len = 64-__builtin_clzll(n);
    bool ans=false;
    for (int i = len; i < 63; i++)
    {
        if(pal(n,i))ans=true;
    }
    cout<<(ans?"YES":"NO")<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}