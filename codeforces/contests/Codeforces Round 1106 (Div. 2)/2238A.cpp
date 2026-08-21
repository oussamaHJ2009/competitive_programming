//problem link: https://codeforces.com/contest/2238/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,c;
    cin>>n>>c;
    vector<int>a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    vector<int>sa=a,sb=b;
    sort(sa.begin(),sa.end());
    sort(sb.begin(),sb.end());
    for(int i=0;i<n;i++){
        if(sa[i]<sb[i]){
            cout<<"-1\n";
            return;
        }
    }
    int cnt = accumulate(a.begin(),a.end(),0) - accumulate(b.begin(),b.end(),0);
    for (int i = 0; i < n; i++)
    {
        if(a[i]<b[i]){
            cnt+=c;
            break;
        }
    }
    cout<<cnt<<'\n';
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