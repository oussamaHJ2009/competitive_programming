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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll sum = 0;
    ll sums=0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
        sums+=a[i]*a[i];
    }
    cout<<(sums*2*n-(2*sum*sum))/2;

    return 0;

}