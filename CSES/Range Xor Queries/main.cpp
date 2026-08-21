#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int>x(n+1);
    x[0]=0;
    for (int i = 0; i < n; i++)
    {
        cin>>x[i+1];
        x[i+1]^=x[i];
    }
    for (int Q = 0; Q < q; Q++)
    {
        int a,b;
        cin>>a>>b;
        int ans=x[b]^x[a-1];
        cout<<ans<<"\n";
    }
    


    return 0;

}