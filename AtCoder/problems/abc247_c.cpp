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
    vector<int> ans(0);
    for (int i = 1; i <= n; i++)
    {
        vector<int> c;
        c.assign(ans.begin(),ans.end());
        ans.push_back(i);
        for (int a : c)
        {
            ans.push_back(a);
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;

}