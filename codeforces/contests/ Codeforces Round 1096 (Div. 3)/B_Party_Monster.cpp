#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnto=0,cntc=0;
        for (int i = 0; i < n; i++)
        {
            char x;
            cin>>x;
            if(x=='(')cnto++;
            else cntc++;
        }
        if(cnto==cntc)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;

}