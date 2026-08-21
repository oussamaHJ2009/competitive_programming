#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>tree(n),deg(n);
    tree[0]=-1;
    for (int i = 1; i <= n-1; i++)
    {
        cin>>tree[i];tree[i]--;
        deg[tree[i]]++;
    }
    queue<int>q;
    vector<int>dp(n);
    for (int i = 0; i < n; i++)
    {
        if(deg[i]==0){
            q.push(i);
            dp[i]=0;
        }
    }
    while (!q.empty())
    {
        int cur=q.front();q.pop();
        if(tree[cur]!=-1){
            dp[tree[cur]]+=dp[cur]+1;
            if(!--deg[tree[cur]])q.push(tree[cur]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<dp[i]<<' ';
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