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
        map<ll,priority_queue<ll>>cnt;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];    
            cnt[a[i]-i].push(a[i]);
        }

        ll ans=0;
        for (auto [k,q]:cnt)
        {
            while (!q.empty())
            {
                ll cont=q.top();q.pop();
                if(!q.empty()) {cont+=q.top();q.pop();}
                else break;
                if(ans+cont>ans)ans+=cont;
                else break;
            }
        }
        
        cout<<ans<<'\n';
    }

    return 0;

}