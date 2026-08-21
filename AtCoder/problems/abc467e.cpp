// problem link: https://atcoder.jp/contests/abc467/tasks/abc467_c
// authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    int s = 0;
    vector<int> val;
    for (int i = 0; i < n - 1; i++)
    {
        s+=
        if (b[i] != (a[i] + a[i + 1]) % 2)
        {
            val.push_back(s);
            s = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

// void solve()
// {
//     int n,m;
//     cin >> n>>m;
//     vector<int> a(n), b(n - 1);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n - 1; i++)
//         cin >> b[i];
//     int lst = -1;
//     vector<int>val;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if(b[i]!=(a[i]+a[i+1])%2){
//             val.push_back(i-lst);
//             lst=i;
//         }
//     }
//     val.push_back(n-1 - lst);
//     int ans1=0,ans2=0;
//     for (int i = 0; i < val.size(); i++)
//     {
//         if(i%2)ans1+=val[i];
//         else ans2+=val[i];
//     }
//     cout<<min(ans1,ans2)<<'\n';
// }
