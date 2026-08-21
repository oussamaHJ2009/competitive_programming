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
        vector<int>a(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        vector<int>d(n);
        d[0]=a[0];
        for (int i = 1; i < n; i++)
        {
            d[i]=a[i]-a[i-1];
        }
        int k=*min_element(d.begin(),d.end());
        k*=-1;
        for (int i = 0; i < n-1; i++)
        {
            if(d[i]<0){d[i]+=k;d[i+1]-=k;}
        }
        if(d[n-1]<0)d[n-1]+=k;
        bool ok=true;
        for (int i = 0; i < n; i++)
        {
            if(d[i]<0)ok=false;
        }
        cout<<(ok?"YES":"NO")<<'\n';
        
    }

    return 0;

}