#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin>>s;
    bool ok=1;
    if((n&1) && s[0]=='b')ok=0;
    for (int i = (n&1); i < n-1; i+=2)
    {
        if(s[i]==s[i+1] && s[i]!='?')ok=0;
    }
    cout<<(ok?"YES":"NO")<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}