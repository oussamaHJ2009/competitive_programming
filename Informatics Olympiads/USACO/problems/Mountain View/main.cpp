#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct M{
    int l,r;
};

bool cmp(M a,M b){
    if(a.l==b.l){
        return a.r>b.r;
    }
    return a.l<b.l;
}

void solve() {
    int n;
    cin>>n;
    vector<M>a(n);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        a[i].l=x-y;
        a[i].r=x+y;
    }
    
    sort(a.begin(),a.end(),cmp);
    M b=a[0];
    int ans=n;
    for(int i=1;i<n;i++){
        if(b.r>=a[i].r)ans--;
        else b=a[i];
    }
    cout<<ans<<'\n';
}

int main() {
    setIO("mountains");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}