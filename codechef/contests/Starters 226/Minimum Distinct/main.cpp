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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        map<int, int> cnt;
        vector<int> dist(n + 1);
        int d= 0;
        for (int i = 0; i < n; i++)
        {
            cnt[a[i]]++;
            if(cnt[a[i]] == 1) d++;
            dist[i] = d;
        }

        for (int i=n-1;i>=k;i--)
        {
            if(dist[i] > dist[i - k])d--;k-=cnt[a[i]];
        }
        
        cout<<d;

    }

    return 0;
}