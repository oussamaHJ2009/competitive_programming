//problem link: https://codeforces.com/contest/1020/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<int>suc,ans;
bool in=false;
void dfs(int u){
    if(ans[u]!=-2){
        if(ans[u]==-1){
            in=true;
            ans[u]=u;
        }
        return;
    }
    ans[u]=-1;
    dfs(suc[u]);
    if(ans[u]==u)in=false;
    else ans[u]=in?u:ans[suc[u]];
}

void solve() {
    int n;
    cin>>n;
    ans=vector<int>(n,-2);
    suc=vector<int>(n,0);
    for(int i=0;i<n;i++){cin>>suc[i];suc[i]--;}
    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]+1<<" \n"[i==n-1];
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}