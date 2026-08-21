#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<string,ll>hc;
map<string,ll>sc;
bool cmp(string a,string b){
    return hc[b]*sc[a] > hc[a]*sc[b];
}
void solve() {
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(auto t:s){
        int cnth=0,cnts=0;
        for(auto c:t){
            if(c=='h')cnth++;
            else cnts++;
        }
        hc[t]=cnth;
        sc[t]=cnts;
    }
    sort(s.begin(),s.end(),cmp);
    ll ans=0;
    ll cnt=0;
    for(auto t:s){
        for(auto c:t){
            if(c=='s')cnt++;
            else ans+=cnt;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}