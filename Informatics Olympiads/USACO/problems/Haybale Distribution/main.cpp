#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()), x.end());
    n=x.size();
    vector<int>pre(n+1,0);
    for(int i=0;i<n;i++){
        pre[i+1] = pre[i]+x[i];
        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}