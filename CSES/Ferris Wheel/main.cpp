#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    int l=0,r=n-1;
    int ans=0;
    while (l<r)
    {
        if(p[r]+p[l]<=x){
            ans++;
            r--;l++;
        }else{
            ans++;
            r--;
        }
    }
    if(l==r)ans++;
    cout<<ans<<'\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}