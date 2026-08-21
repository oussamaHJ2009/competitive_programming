//problem link: https://codeforces.com/contest/2236/problem/F1
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int mod = 1e9+7;
const int MAXA = 500001;

vector<int>cnt(MAXA,0);

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    ll ans=1;
    for(int i=0;i<n;i++)cin>>a[i];
    for (int i = 0; i < n; i++)
    {
        int c=0;
        for (int d = 1; d*d <= a[i]; d++)
        {
            if(a[i]%d==0){
                cnt[d]++;c++;
                if(a[i]/d!=d){cnt[a[i]/d]++;c++;}
            }
        }
        ans=(ans*c)%mod;
    }


    for (int d = 1; d < MAXA; d++)
    {
        if(cnt[d]==n)ans--;
    }
    
    cout<<ans<<'\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}