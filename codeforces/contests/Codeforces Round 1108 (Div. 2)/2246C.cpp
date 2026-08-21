//problem link: https://codeforces.com/contest/2246/problem/C
//authored by a human (i guess?)


#include <bits/stdc++.h>


using namespace std;

using ll = int64_t;

const ll mod = 1e9+7;

ll binpow(ll a, ll b, ll m) {
if(b==-1)return 0;
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    map<ll,ll>cnt;
    set<ll>s;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int c=1;
    vector<ll>seg;
    for (int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1]){
            seg.push_back(c);
            c=1;
        }else c++;
    }
    int m = seg.size();
    ll p=1;
    ll ans=1;
    vector<ll>pref(m+1),suff(m+2);
    pref[0]=1;suff[m+1]=1;
    for (int i = 1; i < m; i++)
    {
        pref[i+1] = pref[i] * binpow(2,seg[i]-1,mod);
    }
    for (int i = m - 1; i >= 0; i--)
    {
        suff[i+1] = suff[i+2] * binpow(2,seg[i]-1,mod);
    }
    a.erase(unique(a.begin(),a.end()),a.end());
    
    for(int i =1;i<=m-2;i++){
        ans+=(pref[i-1] * binpow(2,cnt[a[i-1]]-1,mod) *binpow(2,cnt[a[i]]-1,mod)*suff[i+2])%mod;
    }
    ans*= binpow(2,cnt[-1]-1,mod);
    ans%=mod;
    ans+=suff[1];
    ans%=mod;
    cout<<ans<<'\n';
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