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
        ll x;
        cin>>x;
        vector<int> d;
        int f = 0;
        int n = 0;
        while (x > 0)
        {
            d.push_back(x % 10);
            f+=x%10;
            x/=10;
            n++;
        }
        
        int ans = 0;
        d[n-1]--;
        while (f >= 10)
        {
            f -= d[max_element(d.begin(), d.end()) - d.begin()];
            d[max_element(d.begin(), d.end()) - d.begin()] = 0;
            ans++;
        }
        cout<<ans<<endl;
    }
    

    return 0;

}