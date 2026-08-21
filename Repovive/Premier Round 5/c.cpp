#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,d;
    cin>>n>>d;
    vector<int>a(d);
    vector<vector<pair<int,int>>>cnt(n);
    for(int i=0;i<d;i++)cin>>a[i];
    if(n<4 || d<4){
        cout<<-1<<'\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cnt[(a[(i+1)%n]-a[i]+n)%n].push_back({a[i],a[(i+1)%n]});
    }
    int dif=-1;
    for (int i = 0; i < n; i++)
    {
        if(cnt[i].size()>=2 && cnt[i][1].first!=cnt[i][0].first && cnt[i][1].first!=cnt[i][0].second && cnt[i][1].second!=cnt[i][0].second)dif=i;
    }
    if(dif==-1)cout<<"-1\n";
    else{
        int x1=-1,x2=-1,x3=-1,x4=-1;
        for(auto cur:cnt[dif]){
            if(x1==-1){
                x1=cur.first;x2=cur.second;
            }else{
                if(cur.first!=x2 && cur.second!=x1){
                    x3=cur.second;x4=cur.first;
                }
            }
        }
        cout<<x1<<x2<<x4<<x3<<'\n';
    }
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