#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int n, m, d;
        cin>>n>>m>>d;
        if(d < m){
            cout<<n<<endl;
        }else{
            int ans = n/(1 + d/m) + (n%(1 + d/m) > 0);
            cout<<ans<<endl;
        }
    }
    

    return 0;

}