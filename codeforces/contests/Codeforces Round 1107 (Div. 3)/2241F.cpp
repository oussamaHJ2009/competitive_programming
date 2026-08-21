//problem link: https://codeforces.com/contest/2241/problem/F
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int p1[2]{0,0},p0[2]{0,0},cnt[2]{0,0};
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0')p0[cnt[1]%2]++;
        else cnt[1]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if(s[i]=='1')p1[cnt[0]%2]++;
        else cnt[0]++;
    }
    
    if(p1[1]>0 || p0[1]>0)cout<<"Alice\n";
    else cout<<"Bob\n";
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