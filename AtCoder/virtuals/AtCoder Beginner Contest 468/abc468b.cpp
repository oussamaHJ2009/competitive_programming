/*
*created: 2026-08-11 at 14:34:54
*problem: Corridor Watch, link: https://atcoder.jp/contests/abc468/tasks/abc468_b
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m,d;
    string s;
    cin>>m>>d>>s;
    vector<bool>emp(m,false);
    for(int i=0;i<m;i++){
        if(s[i]=='.')emp[i]=1;
    }
    for(int i=0;i<m;i++){
        if(s[i]=='G'){
            for(int j=i;j<min(m,i+d+1);j++){
                emp[j]=0;
            }
            for(int j=i;j>=max(0,i-d);j--){
                emp[j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)ans+=emp[i];
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}