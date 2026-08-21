//problem link: https://atcoder.jp/contests/abc462/tasks/abc462_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int N = 1e6+2;
ll D[N];

void solve() {
    int n,d;
    for(int i=0;i<N;i++)D[i]=0;
    cin>>n>>d;
    for (int i = 0; i < n; i++)
    {
        int s,t;
        cin>>s>>t;
        if(t-s>=d){
            D[s]++;
            D[t-d+1]--;
        }
    }
    ll ans=0;
    for (int x = 1; x < N; x++)
    {
        D[x]+=D[x-1];
        ans+=(D[x]*(D[x]-1))/2;
    }
    cout<<ans<<'\n';
    
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