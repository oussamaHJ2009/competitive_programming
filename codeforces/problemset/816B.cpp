//problem link: https://codeforces.com/contest/816/problem/B
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int N = 200002;

void solve() {
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>T(N,0);
    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin>>l>>r;
        T[l]++;T[r+1]--;
    }
    for (int i = 1; i < N; i++)
    {
        T[i]+=T[i-1];
    }

    vector<int>ad(N);
    for (int i = 1; i < N; i++)
    {
        if(T[i]>=k)ad[i]=1;
        ad[i]+=ad[i-1];
    }
    

    while (q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<ad[b]-ad[a-1]<<'\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}