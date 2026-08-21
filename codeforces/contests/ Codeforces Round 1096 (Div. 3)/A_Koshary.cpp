#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x%2 && y%2)cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;

}