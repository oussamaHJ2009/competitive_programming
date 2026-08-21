#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<int>ind(n+1);
    for (int i = 2; i <= n; i++)
    {
        cin>>a[i];
    }
    int i=n;
    int ans=0;
    while (i!=1)
    {
        i=a[i];
        ans++;
    }
    cout<<ans;

    return 0;

}