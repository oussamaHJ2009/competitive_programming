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
        vector<int>a(n+1);
        map<int,int>cnt;
        a[n] = 1;
        cnt[1]++;
        for (int i = n-1; i > 0; i--)
        {
            if(!cnt[a[i+1]+i] && a[i+1]+i<=n)a[i] = a[i+1] + i;
            else if(!cnt[a[i+1]-i] && a[i+1]-i<=n && a[i+1]-i>0)a[i] = a[i+1] - i;
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    

    return 0;

}