//problem link: https://atcoder.jp/contests/abc465/tasks/abc465_c
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    deque<int>q;
    bool fl=0;
    int ocnt=0;
    for (int i = 0; i < n; i++)
    {
        if(fl){
            q.push_front(i+1);
        }else q.push_back(i+1);
        if(s[i]=='o'){fl=!fl;ocnt++;}
    }
    if(ocnt%2)reverse(q.begin(),q.end());
    for (auto &&i : q)
    {
        cout<<i<<' ';
    }
    
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