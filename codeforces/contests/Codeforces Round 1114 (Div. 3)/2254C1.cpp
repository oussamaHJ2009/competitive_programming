/*
*created: 2026-08-04 at 16:32:31
*problem: F. Whiplash, link: https://codeforces.com/contest/2254/problem/F
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string a,b;
    cin>>n>>a>>b;
    int ca[2]{0,0},cb[2]{0,0};
    for(int i=0;i<n;i++){
        if(b[i]=='1')cb[i%2]++;
        if(a[i]=='1')ca[i%2]++;
    }
    if((ca[0]!=cb[0] )|| (ca[1] != cb[1])){
        cout<<"NO\n";
    }else{
        cout<<"YES"<<'\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}