#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int>cnt(26);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i]-'a']++;
        if(cnt[s[i]-'a']>(n+1)/2){
            cout<<"No"<<'\n';
            return;
        }
    }
    vector<pair<int,char>>p(26);
    for (int i = 0; i < 26; i++)
    {
        p[i]={cnt[i],'a'+i};
    }
    sort(p.begin(),p.end(),greater<pair<int,char>>());
    string u(n,' ');
    int cur=0;
    for (int i = 0; i < n; i+=2)
    {
        while (p[cur].first==0)
        {
            cur++;
        }
        u[i]=p[cur].second;
        p[cur].first--;
    }
    for (int i = 1; i < n; i+=2)
    {
        while (p[cur].first==0)
        {
            cur++;
        }
        u[i]=p[cur].second;
        p[cur].first--;
    }
    cout<<"Yes\n";
    cout<<u<<'\n';
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