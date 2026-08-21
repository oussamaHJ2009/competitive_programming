/*
*created: 2026-08-08 at 13:00:07
*problem: Inc, Dec, Xor, link: https://atcoder.jp/contests/abc470/tasks/abc470_c
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,Q;
    cin>>n>>Q;
    vector<int>a(n,0);
    unordered_set<int>id;
    queue<int>q;
    int s=0;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int i;cin>>i;i--;
            if(a[i]==0)id.insert(i);
            s^=a[i];
            s^=++a[i];
            cout<<s<<'\n';
        }else{
            for(auto v:id){
                s^=a[v];
                s^=--a[v];
                if(a[v]==0)q.push(v);
            }
            while(!q.empty()){id.erase(q.front());q.pop();}
            cout<<s<<'\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}