//problem link: https://codeforces.com/problemset/problem/701/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int>cnt;
    int ts=0;
    for (auto c:s)
    {
        cnt[c]++;
        if(cnt[c]==1)ts++;
    }
    for (auto c:s)
    {
        cnt[c]=0;
    }
    int cur=1;
    int r=0;
    int ans=n;
    cnt[s[0]]=1;
    for (int l = 0; l < n; l++)
    {
        // if(r<l)r=l;
        while (r<n-1 && cur<ts)
        {
            r++;
            cnt[s[r]]++;
            if(cnt[s[r]]==1)cur++;
        }
        if(cur==ts)ans=min(ans,r-l+1);
        cnt[s[l]]--;
        if(cnt[s[l]]==0)cur--;
    }
    cout<<ans<<'\n';
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