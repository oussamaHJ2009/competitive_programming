//problem link: https://atcoder.jp/contests/abc463/tasks/abc463_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

struct v{
    int l,r;
    bool operator<(const v &y){
        if(r==y.r){
            return l<y.l;
        }
        return r<y.r;
    }
};

void solve() {
    int n,k;
    cin>>n>>k;
    vector<v>c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i].l>>c[i].r;
    }
    sort(c.begin(),c.end());

    int lo=1,hi=1e9;
    int ans=-1;
    while (lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        int cnt=1;
        int cur=0;
        for (int i = 1; i < n; i++)
        {
            if(c[i].l-c[cur].r>=mid){
                cnt++;
                cur=i;
            }
        }
        if(cnt>=k){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}