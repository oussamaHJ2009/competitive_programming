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
        ll ans=0;
        ll ones=0;
        ll slots=0;
        int cnt=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>1){
                cnt++;
                ans+=a[i];
                slots+=a[i]/2 - 1;
            }else ones++;
        }
        ans+=min(slots,ones);
        if(cnt==1 && ones>slots)ans++;
        cout<<(ans>=3?ans:0)<<'\n';
    }

    return 0;

}