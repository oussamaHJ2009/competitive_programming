#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, L;
vector<int> P, D;

int main() {
    cin >> N >> L;
    P.resize(N);
    D.resize(N);
    for (int i=0; i<N; i++) cin >> P[i] >> D[i];
    ll ans=0;
    vector<priority_queue<int>>pqs(L);
    priority_queue<int>nxt;
    for (int i = 0; i < N; i++)
    {
        if(D[i]!=-1){
            pqs[D[i]].push(P[i]);
        }
        else {
            pqs[L-1].push(P[i]);
        }
    }
    for (int i = L-1; i >= 0; i--)
    {
        while (!pqs[i].empty())
        {
            nxt.push(pqs[i].top());
            pqs[i].pop();
        }
        if(!nxt.empty()){
            ans+=nxt.top();
            nxt.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}
