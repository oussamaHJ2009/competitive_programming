/*
there is a bit similar but simpler solution using a set instead of the 2 variables and cnt vec used 
to check by cheking if the A[i] is already in the set
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N;
vector<int>A;
vector<vector<int>>tree;
vector<int>ans;
vector<bool>v;
map<int,int>cnt;
bool track=false;
void dfs(int x){
    if(v[x])return;
    v[x]=true;
    cnt[A[x]]++;
    bool f=false;
    if(cnt[A[x]]>1 || track){
        ans[x]=false;
        if(!track)f=true;
        track=true;
    }
    for (auto u:tree[x])
    {
        dfs(u);
    }
    if(f)track=false;
    cnt[A[x]]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>N;

    A.assign(N,0);
    tree.assign(N,vector<int>());
    ans.assign(N,true);
    v.assign(N,false);

    for (auto &it:A)
    {
        cin>>it;
    }
    for (int i = 0; i < N-1; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < N; i++)
    {
        cout<<(!ans[i]?"Yes":"No")<<"\n";
    }
    

    return 0;

}