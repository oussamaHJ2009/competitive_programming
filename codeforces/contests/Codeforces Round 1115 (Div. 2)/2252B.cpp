/*
*created: 2026-08-06 at 16:11:24
*problem: B. Always Changing, link: https://codeforces.com/contest/2252/problem/B
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int c[2]{0,0};
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])c[s[i]-'0']++;
    }
    if(abs(c[0]-c[1])>1){
        if(c[0]>c[1]){
            if(s[0]=='1')c[1]++;
            if(c[0]-c[1]>1 && n!=1 && s[n-1]=='1')c[1]++;
        }else{
            if(s[0]=='0')c[0]++;
            if(c[1]-c[0]>1 && n!=1 && s[n-1]=='0')c[0]++;
        }
    }
    if(abs(c[0]-c[1])>1)cout<<"-1\n";
    else cout<<c[0]+c[1]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}