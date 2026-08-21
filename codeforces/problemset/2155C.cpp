#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)cin>>a[i];
    // 1 is for right
    // 0 is for left

    int ans=0;
    for (int st = 0; st < 2; st++)
    {
        vector<int>w(n,-1);
        w[0]=st;
        bool ok=1;
        for (int i = 1; i < n; i++)
        {
            int delta=a[i-1]-a[i];
            if(abs(delta)>1){
                cout<<0<<'\n';
                return;
            }
            if(delta==0){
                w[i]=w[i-1]^1;
            }else if(delta==-1){
                w[i]=0;
                if(w[i-1]==1){
                    ok=0;break;
                }
            }else if(delta==1){
                w[i]=1;
                if(w[i-1]==0){
                    ok=0;break;
                }
            }
        }
        if(!ok)continue;
        //verification
        vector<int>R(n+1),L(n+1);
        L[0]=0;R[n]=0;
        for(int i=1;i<=n;i++){
            L[i]=(w[i-1]?0:1)+L[i-1];
        }
        for(int i=n-1;i>=0;i--){
            R[i]=R[i+1]+w[i];
        }
        for (int i = 0; i < n; i++)
        {
            if(R[i]+L[i]-w[i]+1!=a[i])ok=0;
        }
        ans+=ok;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}