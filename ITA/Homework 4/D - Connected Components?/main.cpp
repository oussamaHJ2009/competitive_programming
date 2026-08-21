#include <bits/stdc++.h>
using namespace std;

using ll = long long;



void solve() {
    int n,m;
    cin>>n>>m;
    vector<set<int>>no(n);
    unordered_set<int>unvis;
    while(m--){
        int x,y;cin>>x>>y;
        x--,y--;
        no[x].insert(y);
        no[y].insert(x);
    }
    for(int i=0;i<n;i++)unvis.insert(i);
    vector<int>ans;
    int sz=0;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(unvis.count(i)){
            sz=0;
            q.push(i);
            unvis.erase(i);
            while(!q.empty()){
                sz++;
                int u=q.front();
                q.pop();
                for(auto it = unvis.begin(); it != unvis.end(); ){
                    int v = *it;
                    if(no[u].count(v)){
                        it++;
                        continue;
                    }
                    it = unvis.erase(it);
                    q.push(v);
                }
            }
            ans.push_back(sz);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto x:ans)cout<<x<<' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}