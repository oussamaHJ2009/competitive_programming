#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int n;
vector<int>v;
int mex(int l, int r){
    set<int>m;
    for (int i = 0; i <= n; i++)
    {
        m.insert(i);
    }
    
    while (l>=0 && r<=2*n-1 && v[r]==v[l])
    {
        m.erase(v[l]);
        l--;r++;
    }
    return *m.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        cin>>n;
        vector<int>pos;
        v.assign(2*n,0);
        for (int i = 0; i < 2*n; i++)
        {
            cin>>v[i];
            if(!v[i])pos.push_back(i);
        }
        
        cout<<max({mex(pos[0],pos[0]),mex(pos[1],pos[1]),mex((pos[0]+pos[1])/2,(pos[0]+pos[1]+1)/2)})<<"\n";
    }

    return 0;

}