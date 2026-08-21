#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    ll n;
    cin>>n;
    if(n%12==10 && n<22){
        cout<<-1<<'\n';
    }else{
        ll a=0,b=0;
        if(n%12==10)a=22;
        else a=n%12;
        b=n-a;
        cout<<a<<" "<<b<<'\n';
    }
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