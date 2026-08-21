/*
*created: 2026-08-04 at 15:39:34
*problem: B. Evanescent, link: https://codeforces.com/contest/2254/problem/B
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    int n;
    cin>>n>>s;
    bool d=1;
    int ans=1;
    for(int i=1;i<n-1;i++){
        if(s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]==s[i+1]){
            s.erase(s.begin()+i);d=0;
            break;
        }
    }
    if(d)for(int i=1;i<s.size()-1;i++){
        if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
            s.erase(s.begin()+i);d=0;
            break;
        }
    }

    for(int i=1;i<s.size();i++)if(s[i]!=s[i-1])ans++;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}