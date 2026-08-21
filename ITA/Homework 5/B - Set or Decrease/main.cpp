#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e17;

void solve() {
    int n;
    ll k;
    cin>>n>>k;
    ll sum=0;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a.begin(),a.end(),greater<ll>());
    auto check =[&](ll x){
        ll mn = sum-x;
        ll cur=sum-x;
        ll lst = a[n-1]-x;
        for(int i=0;i<min(x,(ll)n-1);i++){
            cur+=i+1;
            lst++;
            cur-=a[i]-lst;
            mn=min(mn,cur);
        }
        return mn<=k;
    }; 

    ll lo=0,hi=INF;
    ll ans=hi;
    while(lo<=hi){
        ll mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans=mid;
            hi = mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
       solve();
    return 0;
}