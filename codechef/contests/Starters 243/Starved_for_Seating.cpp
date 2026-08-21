//problem link: https://www.codechef.com/START243D/problems/STRSEAT
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int s=0;
    for(auto &it:a){cin>>it;s+=it;}
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+= (((s+a[i]+a[j])/2) > k);
        }
    }
    cout<<ans<<'\n';
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