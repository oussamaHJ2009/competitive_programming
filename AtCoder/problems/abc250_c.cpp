#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    vector<int>ind(n+1);
    for (int i = 0; i < n; i++)
    {
        a[i]=i+1;
        ind[a[i]]=i;
    }
    while (q--)
    {
        int x;cin>>x;
        if(ind[x]+1<n){
            int t=a[ind[x]+1];
            a[ind[x]]=t;
            a[ind[x]+1]=x;
            ind[x]++;
            ind[t]--;
        }else{
            int t=a[ind[x]-1];
            a[ind[x]]=t;
            a[ind[x]-1]=x;
            ind[x]--;
            ind[t]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    

    return 0;

}