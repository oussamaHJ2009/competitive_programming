#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,x,s;
        cin>>n>>x>>s;
        string u;
        cin>>u;
        int empty_t=x;
        int cur=0;
        int ans=0;
        for (int i = 0; i < n; i++)
        {
            cur=0;
            empty_t=x;
            for (int j = 0; j < n; j++)
            {
                if(u[j]=='I' || (u[j]=='A' && j<=i)){
                    if(empty_t>0){
                        empty_t--;
                        cur++;
                    }
                }else if(u[j]=='E'|| (u[j]=='A' && j>i)){
                    if(empty_t<x && cur<(x-empty_t)*s){
                        cur++;
                    }
                }
            }
            ans=max(cur,ans);
        }
        cout<<ans<<'\n';
    }
    
}