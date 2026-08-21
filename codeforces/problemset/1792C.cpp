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
        int n;
        cin >> n;
        vector<int> pos(n + 1);
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            pos[a] = i;
        }
        int k = (n + 1) >> 1;
        while (k > 0 && (k==n-k+1 || (pos[k + 1] > pos[k] && pos[n-k] < pos[n-k+1])))
        {
            k--;
        }
        cout << k << '\n';
    }

    return 0;
}