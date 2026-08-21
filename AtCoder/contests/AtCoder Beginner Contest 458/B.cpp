#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cur=0;
            if(j>0)cur++;
            if(j<m-1)cur++;
            if(i<n-1)cur++;
            if(i>0)cur++;
            cout<<cur<<" ";
        }
        cout<<"\n";
    }
    

    return 0;

}