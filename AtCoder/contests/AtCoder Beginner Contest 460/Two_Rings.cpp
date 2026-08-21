#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll x1,x2,y2,y1,r1,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        ll d=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        cout<<(((r1-r2)*(r1-r2)<=d && d<=(r1+r2)*(r1+r2)) ? "Yes":"No")<<'\n';
    }
    
}