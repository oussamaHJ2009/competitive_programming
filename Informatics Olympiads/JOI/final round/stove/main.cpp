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
    int N,K;
    cin>>N>>K;
    vector<int>T(N);
    for(int i=0;i<N;i++)cin>>T[i];
    int ans = T[N-1] - T[0] + 1;
    priority_queue<int>pq;
    for (int i = 1; i < N; i++)
    {
        pq.push(T[i] - T[i-1] - 1);
    }
    K--;
    while (K--)
    {
        ans-=pq.top();pq.pop();
    }
    cout<<ans<<'\n';
}

int main() {
    setIO("");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}