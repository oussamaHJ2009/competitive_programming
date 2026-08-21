//problem link: https://codeforces.com/contest/755/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){cin>>a[i];a[i]--;}
    int ans=0;
    vector<bool>v(n,false);
    for (int i = 0; i < n; i++)
    {
        if(a[a[i]]==i && !v[i] && !v[a[i]]){
            ans++;
            v[i]=1;
            v[a[i]]=1;
        }
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