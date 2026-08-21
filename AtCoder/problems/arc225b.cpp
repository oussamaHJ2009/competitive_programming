// problem link: https://atcoder.jp/contests/arc225/tasks/arc225_b
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
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int c = 0;
    bool A=false;
    for (int i = 0; i <= n; i++)
    {
        if(a[i])c++;
        else {
            if(c!=2 && c!=0)A=1;
            c=0;
        }
    }
    if(A)cout<<"Alice\n";
    else cout<<"Bob\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}