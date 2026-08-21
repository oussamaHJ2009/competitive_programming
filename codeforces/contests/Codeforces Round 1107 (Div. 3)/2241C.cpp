//problem link: https://codeforces.com/contest/2241/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    string s;cin>>s;
    int c=1;
    for (int i = 1; i < n; i++)
    {
        if(s[i]!=s[i-1])c++;
    }
    if(c==2)cout<<"2\n";
    else cout<<"1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}