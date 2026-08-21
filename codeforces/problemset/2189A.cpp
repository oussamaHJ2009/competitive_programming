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
    while(t--){
        int n;
        int h, l;
        cin>>n>>h>>l;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int x = 0;
        int y = 0;
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] <= h && a[i] <= l)z++;
            else if(a[i] <= h)x++;
            else if(a[i] <= l)y++;
        }
        int ans = min(x, y);
        if(z >= max(x, y) - min(x, y)){
            ans += max(x, y) - min(x, y) + (z - (max(x, y) - min(x, y)))/2;
        }else{
            ans += z;
        }
        cout<<ans<<endl;
    }

    return 0;

}