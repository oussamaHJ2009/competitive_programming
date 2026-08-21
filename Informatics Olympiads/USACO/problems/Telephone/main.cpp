#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>b(n);
    vector<vector<int>>breed(k);
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];b[i]--;
        breed[b[i]].push_back(i);
    }
    vector<string>s(k);
    for(int i=0;i<k;i++)cin>>s[i];


    //0 for L and 1 fot R
    vector<vector<vector<int>>>near(2,vector<vector<int>>(n,vector<int>(k,-1)));
    vector<int>cur(k,-1);
    for(int i=0;i<n;i++){
        cur[b[i]] = i;
        near[0][i]=cur;
    }
    cur.assign(k,-1);
    for(int i=n-1;i>=0;i--){
        cur[b[i]] = i;
        near[1][i]=cur;
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
    vector<ll>d(n,INF);
    d[0]=0;
    pq.push({0,0});
    while (!pq.empty())
    {
        auto [dist,u] = pq.top();pq.pop();
        if(dist>d[u])continue;
        if(s[b[u]][b[n-1]]=='1'){
            if(d[n-1] > dist+n-1-u){
                d[n-1] = dist+n-1-u;
            }
        }
        for(int nxt=0;nxt<k;nxt++){
            if(s[b[u]][nxt]=='1'){
                for(int v:{near[0][u][nxt], near[1][u][nxt]}){
                    if(v==-1)continue;
                    if(d[v]>dist + abs(v-u)){
                        d[v] = dist + abs(v-u);
                        pq.push({d[v],v});
                    }
                }
            }
        }
    }
    
    if(d[n-1]==INF)cout<<"-1\n";
    else cout<<d[n-1]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}