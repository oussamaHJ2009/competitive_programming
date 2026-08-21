#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

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
        vector<vector<int>> a(n);
        vector<int> l(n);
        vector<map<int,int>> c(n);
        int ml = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
            a[i].assign(l[i], 0);
            for (int j = 0; j < l[i]; j++)
            {
                cin >> a[i][j];
                c[i][a[i][j]]++;
            }
            reverse(a[i].begin(), a[i].end());
        }
        sort(a.begin(), a.end(), [](const vector<int> &a, const vector<int> &b) {
            int as = (int)a.size();
            int bs = (int)b.size();
            for (int i = 0; i < min(as, bs); i++) {
                if (a[i] != b[i]) return a[i] < b[i];
            }
            return as < bs;
        });
        vector<int> q;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                cnt[a[i][j]]++;
                if (cnt[a[i][j]] == 1) {
                    q.push_back(a[i][j]);
                }
            }
        }
        
        for (const auto& qi : q) {
            cout << qi << " ";
        }
        cout << endl;
    }

    return 0;
}