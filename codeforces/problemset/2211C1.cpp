#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    bool ok = 1;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    for (int i = 0; i < n-k; i++)
    {
        if(b[i]!=-1 && b[i]!=a[i])ok=0;
    }
    for (int i = k; i < n; i++)
    {
        if(b[i]!=-1 && b[i]!=a[i])ok=0;
    }
    if(n-k<k){
        vector<int>cnt(n+1);
        for (int i = n-k; i < k; i++)
        {
            cnt[a[i]]++;
        }
        for (int i = n-k; i < k; i++)
        {
            if(b[i]!=-1){
                if(cnt[b[i]])cnt[b[i]]--;
                else ok=0;
            }
        }
    }
    cout<<(ok?"YES":"NO")<<'\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
