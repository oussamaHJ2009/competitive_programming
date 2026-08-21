#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n,x,y;

ll dfs(int t,int l){
    if(l==1)return 1&t;
    if(t==0){
        return dfs(0,l-1) + x*dfs(1,l);
    }else{
        return dfs(0,l-1)+ y*dfs(1,l-1);
    }
}

void solve() {
    cin>>n>>x>>y;
    cout<<dfs(0,n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}