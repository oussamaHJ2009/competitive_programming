//problem link: https://codeforces.com/contest/1851/problem/F
//written by a rando


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

using ll = int64_t;


int n,k;
void solve() {
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].f;
        a[i].s=i+1;
    }
    sort(a.begin(),a.end());
    int mn=INT32_MAX;
    int idx;
    for(int i=0;i<n-1;i++){
        if((a[i].f^a[i+1].f)<mn){
            mn=a[i].f^a[i+1].f;
            idx=i;
        }
    }
    int x=((1<<k)-1)^a[idx].f;
    cout<<a[idx].s<<' '<<a[idx+1].s<<' '<<x<<'\n';
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