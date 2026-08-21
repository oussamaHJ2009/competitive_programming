#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int>p(n+1);
    vector<int>q(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>p[i];
        q[p[i]]=i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<q[i]<<" ";
    }
    

    return 0;

}