//problem link: https://atcoder.jp/contests/arc215/tasks/arc215_b
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(2*n);
    for (int i = 0; i < 2*n; i++)
    {
        cin>>a[i];
    }
    vector<int>cnt(n+1,-1);
    vector<int>d;
    int md=1;
    for (int i = 0; i < 2*n; i++)
    {
        if(cnt[a[i]]==-1)cnt[a[i]]=md;
        else if(cnt[a[i]]==md){
            d.push_back(i);
            md^=1;
        }
    }
    cout<<d.size()<<'\n';
    for (auto x : d)
    {
        cout<<x<<' ';
    }
    cout<<'\n';
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