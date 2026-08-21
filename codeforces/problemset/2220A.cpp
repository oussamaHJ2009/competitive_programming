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
        vector<int>a(n);
        vector<int>cnt(101);
        bool ok=true;
        for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
            if(cnt[a[i]]>1)ok=false;
        }
        if(ok){
            sort(a.begin(),a.end(),greater<int>());
            for (auto x:a)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;

}