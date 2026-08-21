#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        for (int i = 1; i < s.size(); i++)
        {
            if(s[i]==s[i-1])cnt++;
        }
        if(cnt<=2)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;

}