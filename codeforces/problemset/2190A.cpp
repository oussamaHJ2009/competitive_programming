#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string T=s;
    sort(T.begin(),T.end());
    vector<int>la;
    for (int i = 0; i < n; i++)
    {
        if(s[i]!=T[i])la.push_back(i+1);
    }
    if(la.size()>0){
        cout<<"Alice\n"<<la.size()<<'\n';
        for (auto l:la)
        {
            cout<<l<<' ';
        }
        cout<<'\n';
    }else{
        cout<<"Bob"<<'\n';
    }
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