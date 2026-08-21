/*
*created: 2026-08-07 at 15:40:18
*problem: B. Hypercarp and the Control Panel, link: https://codeforces.com/contest/2253/problem/B
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool done=0;
    for(int i = 1;i<n-2 && !done;i++){
        if(a[i]==a[i-1] && a[i+1] == a[i+2] && a[i]!=a[i+1]){

            swap(a[i],a[i+1]);
            done=1;
        }
    }

    for(int i = 1;i<n-1 && !done;i++){
        if(a[i]!=a[i-1] && a[i] == a[i+1] && ((i>1 && a[i-2]!=a[i]) || i<=1)){
            swap(a[i],a[i-1]);
            done=1;
        }
    }
&& ((i>1 && a[i-2]!=a[i]) || i<=1)
    for(int i = 1;i<n-1 && !done;i++){
        if(a[i]==a[i-1] && a[i] != a[i+1] && ((i<n-2 && a[i+2]!=a[i]) || i>=n-2)){
            swap(a[i],a[i+1]);
            done=1;
        }
    }

    int ans = n;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1])ans--;
    }

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}