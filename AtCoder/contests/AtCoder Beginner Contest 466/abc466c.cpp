// problem link: https://atcoder.jp/contests/abc466/tasks/abc466_c
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool qry(int i, int j)
{
    cout << "? " << i << ' ' << j << endl;
    string s;
    cin >> s;
    if (s == "Yes")
        return 1;
    else
        return 0;
}

void solve()
{
    int n;
    cin >> n;
    int i = 1, j = 2;
    int ans = 0;
    while (j <= n && i<j)
    {
        
        if(qry(i,j)){
            ans+=j-i;
            j++;
        }
        else i++;
        if(i==j)j++;
    }
    cout << "! " << ans << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}