//problem link: https://codeforces.com/contest/1872/problem/E
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    string s;
    vector<int>a(n);
    for(auto &it:a)cin>>it;
    cin>>s;
    vector<int>p0(n+1,0),p1(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        p0[i]=p0[i-1];
        p1[i]=p1[i-1];
        if(s[i-1]=='1'){
            p1[i]^=a[i-1];
        }
        else{
            p0[i]^=a[i-1];
        }
    }
    int q;
    cin>>q;
    int cur0=p0[n],cur1=p1[n];
    while (q--)
    {
        int qry;
        cin>>qry;
        if(qry==1){
            int l,r;
            cin>>l>>r;
            int sub0=p0[r]^p0[l-1],sub1=p1[r]^p1[l-1];
            cur0^=sub0;
            cur0^=sub1;
            cur1^=sub1;
            cur1^=sub0;
        }else{
            int g;
            cin>>g;
            if(g)cout<<cur1<<' ';
            else cout<<cur0<<' ';
        }
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