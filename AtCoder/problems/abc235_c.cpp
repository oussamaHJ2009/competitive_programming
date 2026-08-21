#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    map<int,vector<int>>cnt;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        cnt[a[i]].push_back(i+1);
    }
    while (q--)
    {
        int x,k;
        cin>>x>>k;
        if(k-1<cnt[x].size())cout<<cnt[x][k-1]<<endl;
        else cout<<-1<<endl;
    }
    

    return 0;

}