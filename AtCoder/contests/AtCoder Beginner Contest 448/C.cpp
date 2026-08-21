#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<pair<int,int>>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first;a[i].second=i;
    }
    sort(a.begin(),a.end());
    while (q--)
    {
        int k;cin>>k;
        int ans=0;
        vector<int> b(k);
        for (int i = 0; i < k; i++)
        {
            cin>>b[i];
        }
        for (int i = 0; i < k; i++)
        {
            for (int i = 0; i < k; i++)
        {
            if(a[ans].second==b[i]-1)ans++;
        }
        }
        
        
        cout<<a[ans].first<<endl;
    }
    


    return 0;

}