#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    int N=2*n;
    vector<ll>a(N+1);
    for (int i = 1; i <=N; i++)
    {
        cin>>a[i];
    }
    vector<ll>L(N+1,0),R(N+2,0),pre1(N+1,0),pre2(N+1,0);
    for (int i = 1; i <= N; i++)
    {
        L[i]=-a[i]+L[i-1];
        pre1[i]=pre1[i-1]+(i&1?a[i]:-a[i]);
        pre2[i]=pre2[i-1]+(i&1?-a[i]:a[i]);
    }
    for (int i = N; i >= 1; i--)
    {
        R[i]=R[i+1]+a[i];
    }
    vector<ll>ans(n+1);
    for (int k = 1; k <= n; k++)
    {
        ans[k]=L[k-1]+R[N-k+2]+(!(k&1)?pre1[N-k+1]-pre1[k-1]:pre2[N-k+1]-pre2[k-1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}