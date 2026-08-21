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
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i]--;
    }
    ll cnt1=0, cnt2=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==i) cnt1++;
        else if(a[a[i]]==i)cnt2++;
    }
    cout<<(cnt1*(cnt1-1))/2+cnt2/2;
    return 0;

}