//problem link: https://codeforces.com/contest/1137/problem/D
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<string> qry(vector<int>a){
    cout<<"next ";
    for(auto x:a)cout<<x<<' ';
    cout<<"\n";
    cout.flush();
    int n;cin>>n;
    vector<string>s;
    for (int i = 0; i < n; i++)
    {
        string f;cin>>f;
        s.push_back(f);
    }
    return s;
}

void solve() {
    vector<int>g(10);
    qry({0});
    auto ss=qry({0,1});
    for (int gc=0;gc<ss.size();gc++)
    {
        for (auto c:ss[gc])
        {
            g[c-'0']=gc;
        }
    }
    while (g[0]!=g[1])
    {
        qry({0});
        auto ss=qry({0,1});
        for(int gc=0;gc<ss.size();gc++)
        {
            for (auto c:ss[gc])
            {
                g[c-'0']=gc;
            }
        }
    }
    while (g[0]!=g[2])
    {
        auto ss=qry({0,1,2,3,4,5,6,7,8,9});
        for(int gc=0;gc<ss.size();gc++)
        {
            for (auto c:ss[gc])
            {
                g[c-'0']=gc;
            }
        }
    }
    cout<<"done\n";
    cout.flush();
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