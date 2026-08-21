#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n;
        int m;
        cin>>n>>m;
        vector<int>a(m);
        for(int i=0;i<m;i++)cin>>a[i];
        ll sum = accumulate(a.begin(),a.end(),0);
        if(sum>n){cout<<-1<<endl;break;}
        
    }

    return 0;

}