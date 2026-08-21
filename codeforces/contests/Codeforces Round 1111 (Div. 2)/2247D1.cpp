// problem link: https://codeforces.com/contest/2247/problem/D1
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

vector<int>id;
vector<int> a;

bool cmp(int i,int j){
    return a[i]<a[j];
}

void solve()
{
    int n, q;
    cin >> n >> q;
    
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