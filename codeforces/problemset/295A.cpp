//problem link: https://codeforces.com/contest/295/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k,m;
    cin>>n>>m>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>L(m),R(m);
    vector<ll> V(m);
    for (int i = 0; i < m; i++)
    {
        cin>>L[i]>>R[i]>>V[i];
    }
    vector<ll>mult(m+1,0);
    for(int q=0;q<k;q++){
        int x,y;cin>>x>>y;
        mult[x-1]++;mult[y]--;
    }
    V[0]*=mult[0];
    for(int q=1;q<m;q++){
        mult[q]+=mult[q-1];
        V[q]*=mult[q];
    }
    vector<ll>dif(n+1,0);
    for(int i=0;i<m;i++){
        dif[L[i]-1]+=V[i];
        dif[R[i]]-=V[i];
    }
    a[0]+=dif[0];
    for (int i = 1; i < n; i++)
    {
        dif[i]+=dif[i-1];
        a[i]+=dif[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<' ';
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