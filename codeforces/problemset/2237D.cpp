// problem link: https://codeforces.com/contest/2237/problem/D
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int p = 0;
    int cnt[3] = {1, 0, 0};
    ll ans = 0;
    int alt=0;
    for(int i=0;i<n;i++){
        p=(p+1+s[i]-'0')%3;
        if(i==0||s[i-1]==s[i])alt=1;
        else alt++;
        ans+=i+1-cnt[p]-(alt-1)/2;
        cnt[p]++;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}