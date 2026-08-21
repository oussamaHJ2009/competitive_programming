// problem link: https://codeforces.com/contest/1520/problem/F1
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool qry(int r,int k)
{
    int ret;
    cout << "? " << 1 << ' ' << r << '\n';
    cout.flush();
    cin >> ret;
    if (ret == -1)
        exit(0);
    return r-ret<k;
}

void solve()
{
    int n, tt, k;
    cin >> n >> tt >> k;
    int lo=0,hi=n;
    while (hi-lo>1)
    {
        int mid=(hi+lo)/2;
        if(qry(mid,k)){
            lo=mid;
        }else{
            hi=mid;
        }
    }
    cout<<"! "<<hi<<'\n';
    cout.flush();
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