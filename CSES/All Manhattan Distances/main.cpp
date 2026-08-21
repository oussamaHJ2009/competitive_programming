#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using lll = __int128;

void print(lll x){
    if(x==0){
        cout<<0;
        return;
    }

    string ret="";
    while(x>0){
        ret+=(x%10) +'0';
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    cout<<ret;
}

void solve() {
    int n;
    cin>>n;
    vector<ll>x(n),y(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    lll ans(0);
    for (int i = 0; i < n; i++)
    {
        ll cont = (x[i]+y[i])*(2*i - n+1);
        ans = ans + cont;
    }
    print(ans);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}