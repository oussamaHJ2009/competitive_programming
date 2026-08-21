#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        vector<map<int, int>> cnt(n);
        int k = 0;
        int ans = 0;
        cnt[0][a[0]] = 1;
        vector<pair<int, int>> lim;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if(a[i] - a[i-1] > 1 || !cnt[k][a[i] - 1]) {
                k++;
                l = i;
                r = i;
            }
            if(a[r] - a[r - 1] == 1 && a[r + 1] - a[r] == 1)
            cnt[k][a[i]]++;
        }
        cout<<ans<<endl;
    }
    
    return 0;

}