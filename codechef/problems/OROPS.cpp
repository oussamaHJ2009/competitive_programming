//problem link: https://www.codechef.com/problems/OROPS
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    int M=0;
    for(auto &it:a){
        cin>>it;
        M|=it;
    }
    int cur=0;
    int k=0;
    for (int i = 0; i < n; i++)
    {
        cur|=a[i];
        if(cur==M){
            k++;
            cur=0;
        }
    }
    cout<<n-k<<'\n';
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