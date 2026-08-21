#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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
        vector<int> b;
        b.assign(a.begin(), a.end());
        sort(b.begin(), b.end());
        int k = 1e9;
        for (int i = 0; i < n; i++){
            if(a[i]!=b[i]){
                int s = min(max(b[n-1]-a[i], a[i]-b[0]), max(b[n-1]-b[i], b[i]-b[0]));
                k=min(s,k);
            }
        }
        if(k == 1e9){
            cout<<-1<<endl;
        }else{
            cout<<k<<endl;
        }

    }

    return 0;
}