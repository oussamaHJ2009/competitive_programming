//problem link: https://codeforces.com/contest/762/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    priority_queue<int,vector<int>,greater<int>>qa,qb,qc;
    for (int i = 0; i < m; i++)
    {
        int v;
        string in;
        cin>>v>>in;
        if(in == "USB"){
            qa.push(v);
        }else{
            qb.push(v);
        }
    }
    ll cnt=0;
    ll price=0;
    while (!qa.empty() && a--)
    {
        cnt++;
        price+=qa.top();
        qa.pop();
    }
    while (!qb.empty() && b--)
    {
        cnt++;
        price+=qb.top();
        qb.pop();
    }
    while(!qa.empty()){
        qc.push(qa.top());
        qa.pop();
    }
    while(!qb.empty()){
        qc.push(qb.top());
        qb.pop();
    }
    while (!qc.empty() && c--)
    {
        cnt++;
        price+=qc.top();
        qc.pop();
    }
    cout<<cnt<<' '<<price<<'\n';
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