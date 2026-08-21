#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] > a[mx])mx=i;
        }
        int x = a[0];
        a[0] = a[mx];
        a[mx] = x;
        for (int i = 0; i < n; i++)
        {
            cout<< a[i]<<" ";
        }
        cout<<endl;
    }
    

    return 0;

}