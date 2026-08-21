//problem link: https://codeforces.com/contest/1387/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll n,m;
const ll MAXN = 100005;
const long double eps = 1e-6;
const ll INF = 1e9;

long double ans[MAXN];
ll K[MAXN],B[MAXN];
bool v[MAXN];
vector<pair<ll,ll>>adj[MAXN];
ll s;
bool odd=false;
vector<ll>comp;
void dfs(ll u){
    v[u]=1;
    comp.push_back(u);
    for (auto [w,c]:adj[u])
    {
        if(!v[w]){
            K[w]= -K[u];
            B[w] = c - B[u];
            dfs(w);
        }else{
            if(K[w]+K[u]!=0){
                double cur = (long double)(c-B[u]-B[w])/(long double)(K[w]+K[u]);
                if(!odd){
                    odd=1;
                    ans[s]=cur;
                }else{
                    if(abs(ans[s]-cur)>eps){
                        cout<<"NO\n";
                        exit(0);
                    }
                }

            }else{
                if(abs(c-B[w]-B[u])>eps){
                    cout<<"NO\n";
                    exit(0);
                }
            }
        }
    }
    if(odd){
        if(abs(ans[u]-INF)<=eps)ans[u]=K[u]*ans[s]+B[u];
        else if(abs(ans[u]-K[u]*ans[s]-B[u])>eps){
            cout<<"NO\n";
            exit(0);
        }
    }
}

map<tuple<ll,ll,ll>,bool>given;

void solve() {
    for (ll i = 0; i < MAXN; i++)
    {
        adj[i].clear();
        B[i]=0;
        ans[i]=INF;
        K[i]=0;
        v[i]=false;
    }
    cin>>n>>m;
    for (ll i = 0; i < m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        if(a==b && abs(ans[a]-INF)>eps && abs(ans[b]-INF)>eps){
            ans[a]=c/2;
            ans[b]=c/2;
        }else if(a==b && (abs(ans[a]-INF)>eps || abs(ans[b]-INF)>eps)){
            cout<<"NO\n";
            exit(0);
        }
        if(!given[{a,b,c}] && !given[{b,a,c}]){
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            given[{a,b,c}]=true;
        }
    }
    for(ll i=0;i<n;i++)if(adj[i].size()==0)ans[i]=0;

    for (ll i = 0; i < n; i++)
    {
        if(!v[i]){
            odd=false;
            comp.clear();
            s=i;
            K[s]=1;
            B[s]=0;
            dfs(s);
            if(!odd){
                vector<long double>ss;
                for (auto x:comp)
                {
                    ss.push_back(-K[x] * B[x]);
                }
                sort(ss.begin(),ss.end());
                long double X = ss[(ss.size())/2];
                for (auto x : comp)
                {
                    ans[x]=K[x]*X+B[x];
                }
            }else{
                for (auto x : comp)
                {
                    ans[x]=K[x]*ans[s]+B[x];
                }
            }
        }
    }
    
    cout<<"YES\n";
    for (ll i = 0; i < n; i++)
    {
        cout<< fixed << setprecision(6)<<ans[i]<<' ';
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}


