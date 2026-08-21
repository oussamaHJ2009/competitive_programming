#include <bits/stdc++.h>
using namespace std;

int sumd(long long v){
    int s=0;
    while(v>0){ s += v%10; v/=10; }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        long long x; cin>>x;
        int ans=0;
        for(int s=1;s<=90;s++){
            long long y = x + s;
            if(sumd(y)==s) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
