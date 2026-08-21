//problem link: https://codeforces.com/contest/2237/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    vector<int>sa=a;
    sort(sa.begin(),sa.end());
    for (int i = 0; i < n; i++)
    {
        if(b[i]<sa[i]){
            cout<<-1<<'\n';
            return;
        }
    }
    
    vector<int>rep(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(rep[j]==-1 && a[j]<=b[i]){
                rep[j]=i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i]=b[rep[i]];
    }
    
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[i])ans++;
        }
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