#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>s(n);
    iota(s.begin(),s.end(),0);
    for (int i = 0; i < k; i++)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        swap(s[a],s[b]);
    }
    
}

int main()
{
    setIO("");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}