#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        ll a,b; cin>>a>>b;
        ll s0=0, s1=0;
        int ans=0;
        for(int i=0;i<31;i++){
            if(i%2==0) s0 += 1LL<<i; else s1 += 1LL<<i;
            if( (s0<=a && s1<=b) || (s0<=b && s1<=a) ) ans = i+1;
            else break;
        }
        cout<<max(1,ans)<<"\n";
    }
}
