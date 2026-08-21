#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>w(n);
        vector<int>m(3,0);
        for (int i = 0; i < n; i++)
        {
            cin>>w[i];
            m[w[i]%3]++;
        }
        int ans=m[0]+ min(m[1],m[2]) + (max(m[1],m[2])-min(m[1],m[2]))/3;
        cout<<ans<<endl;
    }

    return 0;

}