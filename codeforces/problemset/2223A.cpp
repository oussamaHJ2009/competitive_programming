#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    string ta="",tb="";
    bool ok=1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==b[i]){ta+=a[i];tb+=a[i];}
        else{
            ta+=(ok?'(':')');
            tb+=(ok?')':'(');
            ok^=1;
        }
    }
    int ca=0,cb=0;
    ok=1;
    for (int i = 0; i < n; i++)
    {
        if(ta[i]=='(')ca++;else ca--;
        if(tb[i]=='(')cb++;else cb--;
        if(ca<0||cb<0)ok=0;
    }
    if(ca!=0||cb!=0)ok=0;
    cout<<(ok?"YES":"NO")<<'\n';
}

int main(){
    int t;cin>>t;
    while(t--)solve();
}