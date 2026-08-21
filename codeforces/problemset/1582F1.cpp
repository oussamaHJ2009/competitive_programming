/*
 *created: 2026-07-31 at 17:48:02
 *problem: F1. Korney Korneevich and XOR (easy version), link: https://codeforces.com/problemset/problem/1582/F1
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int A = 512;
int dp[A][A]{0};
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<A;i++)dp[0][i]=1;
    for(int x:a){
        if(x==0)continue;
        for(int i=0;i<A;i++){
            dp[i^x][x]|=dp[i][x-1];
            if(dp[i^x][x]){
                int j = x+1;
                while(j<A && !dp[i^x][j])dp[i^x][j++]=1;
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<A;i++){
        if(dp[i][A-1])ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(auto an:ans)cout<<an<<' ';
    cout<<'\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}