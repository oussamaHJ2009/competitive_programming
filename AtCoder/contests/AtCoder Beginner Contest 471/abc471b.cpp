/*
*created: 2026-08-15 at 13:00:06
*problem: Survey Tabulation, link: https://atcoder.jp/contests/abc471/tasks/abc471_b
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    map<string,int>cnt;
    int ans=1;
    while(n--){
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        ans=max(ans,++cnt[s]);

    }
    cout<<ans<<'\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}