//problem link: https://codeforces.com/contest/2008/problem/E
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>>suf(2,vector<int>(26,0));
    for (int i = 0; i < n; i++)suf[i%2][s[i]-'a']++;
    int ans;
    if(n%2==0){
        int a=0,b=0;
        for(int i=0;i<26;i++){
            a=max(a,suf[0][i]);
            b=max(b,suf[1][i]);
        }
        ans=n-a-b;
    }else{
        ans=n+1;
        vector<vector<int>>pre(2,vector<int>(26,0));
        for (int i = 0; i < n; i++)
        {
            suf[i%2][s[i]-'a']--;
            int best[2]={0,0};
            for(int j=0;j<26;j++){
                best[0]=max(best[0],pre[0][j]+suf[1][j]);
                best[1]=max(best[1],pre[1][j]+suf[0][j]);
            }
            ans=min(ans,n-best[0]-best[1]);
            pre[i%2][s[i]-'a']++;
        }
    }

    cout<<ans<<'\n';
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