//problem link: https://codeforces.com/gym/102951/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int N,X;
    cin>>N>>X;
    vector<int>a(N);
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int s=0;
    int ans=0;
    for(int i=0;i<N;i++){
        s+=a[i];
        if(s<=X)ans++;
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