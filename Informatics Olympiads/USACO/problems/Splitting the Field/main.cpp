#include <bits/stdc++.h>
#define f first
#define s second

using ll = int64_t;
const ll INF = 1e9 + 5;

using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}
int n;
vector<pair<ll,ll>>cows;

ll calc(){
    sort(cows.begin(),cows.end());
    vector<ll>smin(n+1,INF),smax(n+1,0);
    for (int i = n-1; i >= 0; i--)
    {
        smin[i] = min(smin[i+1],cows[i].s);
        smax[i] = max(smax[i+1],cows[i].s);
    }
    
    ll ret=0;
    ll mxa = (smax[0] - smin[0])*(cows[n-1].f - cows[0].f);
    ll a1=0,a2=0;
    ll pmin=INF,pmax=0;
    for (int i = 0; i < n-1; i++)
    {
        pmin=min(cows[i].s,pmin);
        pmax=max(cows[i].s,pmax);
        a1 = (cows[i].f - cows[0].f) * (pmax - pmin);
        a2 = (cows[n-1].f - cows[i+1].f) * (smax[i+1] - smin[i+1]);
        ret=max(ret, mxa - a1 - a2);
    }
    
    return ret;
}

void solve()
{
    cin>>n;
    cows.assign(n,{0,0});
    for (int i = 0; i < n; i++)
    {
        cin>>cows[i].f>>cows[i].s;
    }
    ll ans = calc();
    for (int i = 0; i < n; i++)
    {
        swap(cows[i].f,cows[i].s);
    }
    ans=max(ans, calc());
    
    cout<<ans<<'\n';
}

int main()
{
    setIO("split");
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}