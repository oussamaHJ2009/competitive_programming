#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<int>suc;
vector<int>ans;
int len=1;
bool in=false;

void dfs(int u){
    if(ans[u]!=-2){
        if(ans[u]==-1){
            in=true;
            ans[u]=0;
        }
        return;
    }
    ans[u]=-1;
    dfs(suc[u]);
    if(ans[u]==0 && in){
        int a=suc[u];
        while (a!=u)
        {
            len++;
            a=suc[a];
        }
        ans[u]=len;
        a=suc[u];
        while (a!=u)
        {
            ans[a]=len;
            a=suc[a];
        }
        in=false;
        len=1;
    }else if(ans[u]==-1 && !in){
        ans[u]=ans[suc[u]]+1;
    }
}

void solve() {
    int n;
    cin>>n;
    suc=vector<int>(n,0);
    ans=vector<int>(n,-2);
    for(int i=0;i<n;i++){
        cin>>suc[i];
        suc[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];

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