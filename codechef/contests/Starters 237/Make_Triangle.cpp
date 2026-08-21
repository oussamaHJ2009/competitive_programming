#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        vector<int>T(3);
        for (int i = 0; i < 3; i++)
        {
            cin>>T[i];
        }
        sort(T.begin(),T.end());
        int ans = 0;
        while (T[0]+T[1]<=T[2])
        {
            T[0]++;
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}