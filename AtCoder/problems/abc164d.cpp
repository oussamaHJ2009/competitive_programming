//problem link: https://atcoder.jp/contests/abc164/tasks/abc164_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int>S(n+1,0);
    vector<int>cnt(2019,0);
    cnt[0]++;
    ll ans=0;
    int p10=10;
    for (int i = n - 1; i >= 0; i--)
    {
        S[i]=(S[i+1] + p10*(s[i]-'0'))%2019;
        p10=(p10*10)%2019;
        ans+=cnt[S[i]];
        cnt[S[i]]++;
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