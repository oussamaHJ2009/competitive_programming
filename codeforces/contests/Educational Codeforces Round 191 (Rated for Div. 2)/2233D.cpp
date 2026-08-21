#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    map<int,vector<int>>tr;
    map<int,int>cnt;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        int mk;
        cin>>mk;
        if(!tr[mk].empty() && i-tr[mk].back() > 1)cnt[mk]++;
        tr[mk].push_back(i);
        a[i]=mk;
    }
    vector<int> f;
    for (auto [x,y]:cnt)
    {
        if(y>0)f.push_back(x);
        if(y>2){
            cout<<"NO\n";
            return;
        }
    }
    if(f.size()>2){
        cout<<"NO"<<'\n';
        return;
    }
    if(f.size()==1){
        bool fl=0;
        int x1=-1;
        for (int i = 0; i < n; i++)
        {
            if(fl && x1==-1 && a[i]!=f[0])x1=a[i];
            if(x1!=-1 && fl && a[i]!=f[0] && a[i]!=x1){
                cout<<"NO\n";
                return;
            }
            if(a[i]==f[0]){
                if(fl)break;
                fl=1;
            }
        }
        
    }
    cout<<"YES"<<'\n';
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