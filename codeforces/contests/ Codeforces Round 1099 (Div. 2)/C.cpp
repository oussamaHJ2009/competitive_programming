#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        ll val=*min_element(a.begin(),a.end());
        ll cntval=0,cntval1=0,cnt1=0;
        bool fval=false,fval1=false;
        for (int i = 0; i < n; i++)
        {
            fval=(a[i]==val);
            fval1=(a[i]==val+1);
            if(val==1 && a[i]==1)cntval1++;
            while (a[i]!=1)
            {
                if(a[i]%2){a[i]++;}
                else {a[i]/=2;}
                if(!fval)cntval++;
                if(!fval1)cntval1++;
                cnt1++;
                if(a[i]==val)fval=true;
                if(a[i]==val+1)fval1=true;
            }
            
        }
        cout<<min({cnt1,cntval,cntval1})<<'\n';

    }

    return 0;

}