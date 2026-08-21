// problem link: https://atcoder.jp/contests/abc466/tasks/abc466_d
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> R(m), C(m);
    for (int i = 0; i < m; i++)
    {
        cin >> R[i] >> C[i];
    }
    vector<bool> rt(n, 0), ct(n, 0);
    int cnt = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        if(!rt[R[i]-1] && !ct[C[i]-1]){
            cnt++;
        }
        rt[R[i]-1]=1;
        ct[C[i]-1]=1;
    }
    cout<<cnt<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}