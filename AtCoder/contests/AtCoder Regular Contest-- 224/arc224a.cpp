// problem link: https://atcoder.jp/contests/arc224/tasks/arc224_a
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    ll K;
    cin >> K;
    ll ans=K;
    bool f=1;
    for (;  ans<=K*100 && f;ans+=K)
    {
        string cur = to_string(ans);
        for (int j = 1; j < cur.size(); j++)
            if(cur[j]==cur[j-1] && cur[j]=='0')f=0;
        
        }
    cout<<ans-K<<'\n';
    
    
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