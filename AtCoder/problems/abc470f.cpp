/*
*created: 2026-08-08 at 18:42:24
*problem: Googol Swaps, link: https://atcoder.jp/contests/abc470/tasks/abc470_f
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 200005;
const ll mod = 998244353;

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modI(ll a, ll m) {
    return binpow(a, mod - 2);
}

ll Mdiv(ll a, ll b) {
    return (a * modI(b, mod)) % mod;
}

ll fa[N];

vector<vector<ll>>g;
vector<ll>vis;
ll sz=0;
vector<ll>cnt;
string s;
void dfs(ll u){
    if(vis[u])return;
    vis[u]=1;
    cnt[s[u]-'a']++;
    sz++;
    for(auto v:g[u])dfs(v);
}

void solve() {
    ll n,m;
    cin>>n>>m>>s;
    g.assign(n,vector<ll>());
    vis.assign(n,false);
    ll ans=1;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt.assign(26,0);
            sz=0;
            dfs(i);
            ll C = 1;
            for(int j=0;j<26;j++){
                if(cnt[j]==0)continue;
                C = (C * fa[cnt[j]])%mod;
            }
            ans = (ans * Mdiv(fa[sz],C))%mod;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fa[0]=1;
    for(ll i=1;i<N;i++)fa[i]=(fa[i-1]*i)%mod;
    solve();
    return 0;
}