#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        vector<int>pref(n);
        pref[0]=(s[0]=='1' || s[0]=='3');
        for (int i = 1; i < n; i++)
        {
            pref[i]=pref[i-1]+(s[i]=='1' || s[i]=='3');
        }
        int del=0;
        int cnt=0;
        int ans=1e6;
        for (int i = n-1; i >= 0; i--)
        {
            if(s[i]=='1' || s[i]=='3')del=cnt;
            if(s[i]=='2'){
                ans=min(ans,pref[i]+del);
                cnt++;
            }
        }
        ans=min(ans,del);
        for (int i = 0; i < n; i++)
        {
            ans+=(s[i]=='4');
        }
        
        cout<<ans<<'\n';
    }

    return 0;

}