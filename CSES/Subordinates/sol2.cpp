#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<vector<int>>children;
vector<int>sub_tree_size;

void dfs(int u){
    for (auto child : children[u])
    {
        dfs(child);
        sub_tree_size[u]+=sub_tree_size[child];
    }
}

void solve() {
    int n;
    cin>>n;
    children.assign(n,vector<int>());
    sub_tree_size.assign(n,1);
    for (int i = 1; i < n; i++)
    {
        int parent;
        cin>>parent;
        parent--;
        children[parent].push_back(i);
    }
    dfs(0);
    for(auto sub_tree:sub_tree_size){
        cout<<sub_tree-1<<' ';
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