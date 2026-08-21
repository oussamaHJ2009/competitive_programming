/*
*created: 2026-08-15 at 13:00:06
*problem: Chargers, link: https://atcoder.jp/contests/abc471/tasks/abc471_d
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int Q,V;
    cin>>Q>>V;
    priority_queue<int>pq;
    while(Q--){
        int q;
        cin>>q;
        if(q==1){
            int t,w;
            cin>>t>>w;
            pq.push(w-t);
        }else{
            int t;cin>>t;
            if(pq.empty()){
                cout<<"-1\n";
            }else{
                cout<<max(0,min(V, pq.top() + t))<<'\n';
                pq.pop();
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}