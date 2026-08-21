#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int N;
    cin>>N;
    vector<pair<int,int>>cnt(N);
    for(auto &[x,y]:cnt)cin>>y>>x;
    sort(cnt.begin(),cnt.end());
    int l=0,r=N-1;
    int ans=0;
    while(l<=r){
        ans=max(ans,cnt[l].f+cnt[r].f);
        int sub = min(cnt[l].s,cnt[r].s);
        if(l==r)sub/=2;
        cnt[l].s-=sub;
        cnt[r].s-=sub;
        if(cnt[l].s==0)l++;
        if(cnt[r].s==0)r--;
    }
    cout<<ans<<'\n';
}

int main() {
    setIO("pairup");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}