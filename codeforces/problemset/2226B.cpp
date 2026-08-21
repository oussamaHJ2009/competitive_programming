#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for (int i = 1; i < n; i++)
        {
            if(gcd(a[i],a[i-1])==abs(a[i]-a[i-1]))ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;

}