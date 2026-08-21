#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t;
    cin>>t;
    while (t--)
    {
        int z;
        cin>>z;
        ll ans=z*(z-2);
        int s=0;
        while (s*s<=z)s++;
        s--;
        ans+=s;
        for (int i = 1; i <= s; i++)
        {
            ans-=2*((z/i) - (s/i));
        }
        

        cout<<ans<<'\n';
    }
    

}