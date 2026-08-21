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
        vector<int>cnt(n*n+1);
        int ans=0;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin>>x;
                cnt[x]++;
                if(cnt[x]>n*(n-1))ok=false;
            }
            
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;

}