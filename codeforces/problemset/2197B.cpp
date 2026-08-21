#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> p(n);
        vector<int> a(n);
        map<int, int> c;
        for (int i = 0; i < n; i++)
        {
            cin>>p[i];
            c[p[i]]=i;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        map<int, int> cnt;
        bool ok = true;
        cnt[a[0]]=1;
        for (int i = 1; i < n; i++)
        {
            if(a[i-1]!=a[i]){
                cnt[a[i]]++;
            }
            if(cnt[a[i]]>1){
                ok=false;
                break;
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else{
                for (int i = 1; i < n; i++)
                {
                    if(c[a[i]]<c[a[i-1]] && a[i]!=a[i-1])ok=false;
                }
            if(ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    

    return 0;

}