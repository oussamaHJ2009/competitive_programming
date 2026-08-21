#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define all(v) v.begin(),v.end()
#define sorted(s) sort(all(s))
#define rsort(s) sort(s.rbegin(),s.rend())
#define len(s) s.size()
const ll mod=998244353;
const ll mod2=1000000007;
const ld pi=acos(-1);
void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    ll sm=0;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(auto&j:v[i]){
            cin>>j;
            sm+=j;
            a[i]+=j;
        }
    }
    if(sm<=1){
        string ans="";
        for(int i=0;i<n;i++)ans+='D';
        for(int i=0;i<m;i++)ans+='R';
        cout<<0<<endl<<ans<<endl;
        return;
    }
    ll s=sm/2;
    string ans="";
    bool f=1;
    ll c=0;
    for(int i=0;i<n;i++){
        c+=a[i];
        if(f==1&&c>=s){
            bool ok=1;
            f=0;
            for(int j=0;j<m;j++){
                c-=v[i][j];
                if(ok==1&&c==s-1){
                    ans+='D';
                    ans+='R';
                    ok=0;
                }
                else ans+='R';
            }
        }
        else ans+='D';
    }
    cout<<(sm%2==0?s*s:s*(s+1))<<endl<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
