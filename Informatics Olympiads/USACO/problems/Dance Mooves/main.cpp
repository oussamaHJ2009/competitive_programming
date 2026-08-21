#include <bits/stdc++.h>
using namespace std;

void unordered_setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>suc(n);
    iota(suc.begin(),suc.end(),0);
    vector<unordered_set<int>>vs(n);
    for(int i=0;i<n;i++)vs[i].insert(i);
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        swap(suc[a],suc[b]);
        vs[suc[a]].insert(a);
        vs[suc[b]].insert(b);
    }
    vector<int>col(n,-1);
    int cur=0;
    for (int i = 0; i < n; i++)
    {
        if(col[i]==-1){
            int c=i;
            while (col[c]==-1)
            {
                col[c]=cur;
                c=suc[c];
            }
            cur++;
        }
    }
    
    vector<unordered_set<int>>uni(cur);
    for (int i = 0; i < n; i++)
        for (auto x:vs[i])
            uni[col[i]].insert(x);
    for (int i = 0; i < n; i++)
    {
        cout<<uni[col[i]].size()<<'\n';
    }
    
}

int main() {
    unordered_setIO("");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}