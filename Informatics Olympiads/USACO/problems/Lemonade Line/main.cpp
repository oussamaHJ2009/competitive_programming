#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<int>w;

void solve() {
    int N;
    cin>>N;
    w.assign(N,0);
    for (int i = 0; i < N; i++)
    {
        cin>>w[i];
    }
    sort(w.begin(),w.end());
    int ans=0;
    for (int i = 0; i < N; i++)
    {
        if(w[i]>=N-i-1)ans++;
    }
    cout<<ans<<'\n';
}

int main() {
    setIO("lemonade");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}