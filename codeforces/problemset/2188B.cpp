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
        int cnt=0;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            a[i]= c -'0';
            cnt+=a[i];
        }
        vector<int> seg(n, 0);
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            seg[s]+=!a[i];
            if(i==n-1)seg[s]+=!a[i];
            if(i==0)seg[s]+=!a[i];
            s+=a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cnt+=seg[i]/3;
        }
        cout<<cnt<<endl;
    }
    

    return 0;

}