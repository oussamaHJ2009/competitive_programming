#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s.begin(),s.end());

    vector<vector<string>>best;
    int res=0;
    do{
        int ans=0;
        int cnt=0;
        for(auto t:s){
            for(auto c:t){
                if(c=='s')cnt++;
                else ans+=cnt;
            }
        }
        if(res<ans)res=ans;
    }while(next_permutation(s.begin(),s.end()));

    do{
        int ans=0;
        int cnt=0;
        for(auto t:s){
            for(auto c:t){
                if(c=='s')cnt++;
                else ans+=cnt;
            }
        }
        if(res==ans){best.push_back(s);res=ans;}
    }while(next_permutation(s.begin(),s.end()));
    cout<<res<<'\n';
    // int idx=1;
    // for(auto cur:best){
    //     cerr<<idx<<":\n";
    //     idx++;
    //     for(auto t:cur)cerr<<t<<'\n';
    //     cerr<<'\n';
    // }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}