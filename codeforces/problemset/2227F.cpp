#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll>a(n+1);
        vector<ll>cnt(n+1);
        for (int i =1; i <= n; i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        vector<ll>h(n+1);
        h[n]=cnt[n];
        for (int i = n-1; i >=1; i--)
        {
            h[i]=h[i+1] + cnt[i];
        }
        ll I=0,F=0;
        for (int i = 1; i <= n; i++)
        {
            I+=a[i]*i;
            F+=(h[i]*(2*n - h[i] + 1))/2;
        }
        ll mx=0;
        for(int i = 1; i <= n; i++) mx = max(mx, i - n + h[a[i]] - 1);
        cout<<F-I+mx<<'\n';
    }
}