#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int>ind(n+1);
    vector<int>cnt(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        ind[a]=i;
        cnt[(a-i+n)%n]++;
        
    }
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        cnt[(x+n-ind[x])%n]--;
        cnt[(y+n-ind[y])%n]--;
        int t=ind[x];
        ind[x]=ind[y];
        ind[y]=t;
        cnt[(x+n-ind[x])%n]++;
        cnt[(y+n-ind[y])%n]++;
        if(cnt[(x+n-ind[x])%n]==n || cnt[(y+n-ind[y])%n]==n)cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
    

    return 0;

}