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
        vector<int>b(n);
        vector<int>pref(n),suff(n);
        for (int i = 0; i < n; i++){cin>>b[i];}
        for (int i = 0; i < n; i++)
        {
            pref[i]=b[i]+i;
            suff[i]=b[i]-i;
        }
        
        for (int i = 1; i < n; i++)
        {
            pref[i]=max(pref[i],pref[i-1]);
        }
        for (int i = n-2; i >= 0; i--)
        {
            suff[i]=max(suff[i+1],suff[i]);
        }
        int ans=0;
        for (int i = 1; i < n-1; i++)
        {
            ans=max(ans, b[i]+suff[i+1]+pref[i-1]);
        }
        cout<<ans<<endl;
    }

    return 0;

}