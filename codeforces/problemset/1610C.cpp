#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1),b(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i]>>b[i];
        }
        int lo=1,hi=n;
        int ans=1;
        while (lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            int cnt=0;
            for (int i = 1; i <= n; i++)
            {
                if(a[i]>=mid-cnt-1 && b[i]>=cnt)cnt++;
                if(cnt==mid)break;
            }
            if(cnt==mid){
                lo=mid+1;
                ans=mid;
            }
            else hi=mid-1;
        }
        cout<<ans<<endl;
    }

    return 0;

}