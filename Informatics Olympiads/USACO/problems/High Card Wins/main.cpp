#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int>cnt(2*n,1);
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        cnt[--a[i]]--;
    }
    for (int i = 2*n-2; i >= 0; i--)
    {
        cnt[i]+=cnt[i+1];
    }
    sort(a.begin(),a.end(),greater<int>());
    int c=0;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(cnt[a[i]]>c){
            c++;
            ans++;
        }
    }
    cout<<ans<<'\n';
    
}

int main() {
    setIO("highcard");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}