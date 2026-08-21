#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>p(n),d(n),e(n);
    for(int i=1;i<n;i++){
        cin>>p[i]>>d[i]>>e[i];
        p[i]--;
    }
    vector<ll>E(n,0);
    vector<vector<int>>top11(n);
    top11[0]=vector<int>(11,-1);
    for(int i=1;i<n;i++){
        E[i]=E[p[i]]+e[i];
        top11[i] = top11[p[i]];
        top11[i].push_back(d[i]);
        sort(top11[i].begin(),top11[i].end(),greater<int>());
        top11[i].resize(11);
    }

    vector<vector<pair<int,ll>>>pc(11,vector<pair<int,ll>>(n));
    for(int i=0;i<11;i++){
        for(int j=0;j<n;j++){
            pc[i][j]={top11[j][i],E[j]};
        }
        sort(pc[i].begin(),pc[i].end());
        for(int j=1;j<n;j++){
            pc[i][j].second = max(pc[i][j].second,pc[i][j-1].second);
        }
    }


    int m;
    cin>>m;
    int S,C;
    for(int i=0;i<m;i++){
        cin>>S>>C;
        int idx = lower_bound(pc[C].begin(),pc[C].end(),make_pair(S+1,-1LL)) - pc[C].begin();
        cout<<pc[C][idx-1].second<<'\n';
    }



}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}