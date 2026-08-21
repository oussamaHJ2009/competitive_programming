#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(k);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin>>b[i];
        b[i]--;
    }
    int mx = a[max_element(a.begin(),a.end())-a.begin()];
    bool ok=false;
    for (int i = 0; i < k; i++)
    {
        if(a[b[i]]==mx)ok=true;
    }
    if(ok)cout<<"Yes";
    else cout<<"No";

    return 0;

}