//problem link: https://www.codechef.com/START243D/problems/OROPS
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    ll ors=0;
    for(auto &it:a){cin>>it;ors|=it;}
    vector<pair<int,int>>sub;
    int l=-1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==ors)continue;
        l=i;
        while (i<n && a[i] != ors)i++;
        i--;
        sub.push_back({l,i});
    }
    int ans=0;
    for (auto [l,r]:sub)
    {
        int cnt=0,cur_or=0;
        for (int i = l; i <= r; i++)
        {
            cnt++;cur_or|=a[i];
            if(cur_or==ors){
                ans+=cnt-1;
                cur_or=0;
                cnt=0;
            }
        }
        if(cnt!=0)ans+=cnt;
    }
    
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}