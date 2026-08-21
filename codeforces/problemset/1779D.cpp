/*
*created: 2026-08-02 at 10:00:10
*problem: D. Boris and His Amazing Haircut, link: https://codeforces.com/contest/1779/problem/D
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n;
    vector<int>a(n),b(n);
    for(int &it:a)cin>>it;
    for(int &it:b)cin>>it;
    cin>>m;
    vector<int>x(m);
    for(int &it:x)cin>>it;
    map<int,int>cnt;
    for(int u:x)cnt[u]++;
    for(int i=0;i<n;i++)
    if(b[i]>a[i]){
        cout<<"NO\n";
        return;
    }
    
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()<b[i])st.pop();
        if(a[i]>b[i]){
            if(st.empty() || st.top()!=b[i]){
                st.push(b[i]);
                cnt[b[i]]--;
                if(cnt[b[i]]<0){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }

    cout<<"YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) 
        solve();
    return 0;
}