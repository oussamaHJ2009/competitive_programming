#include<bits/stdc++.h>
using namespace std;
int n,k,m;
signed main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        if(k-1<n-k)k=n+1-k;
        int a=0,b=0;
        while(1){
            if(b<n-k&&a+(b+1)+max(a,b+1)-1<=m)++b;
            if(a<k-1&&(a+1)+b+max(a+1,b)-1<=m)++a;
            else break;
        }
        cout<<a+b+1<<endl;
    }
}