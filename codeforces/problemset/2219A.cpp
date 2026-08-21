#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int q,p;
        cin>>p>>q;
        ll t=p + 2*q;
        ll lim=sqrt(t);
        ll an=-1,am=-1;
        for (int n = 1; n <= lim; n++)
        {
            ll den = 2*n+1;
            ll nem = p+2*q-n;
            if(nem%den==0 && nem/den>0){
                ll m = nem/den;
                if(abs(m-n)<=p){
                    an=n;
                    am=m;
                    break;
                }
            }
        }
        if(an==-1)cout<<-1<<'\n';
        else cout<<an<<' '<<am<<'\n';
    }
}