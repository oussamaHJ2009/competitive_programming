#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>s(n);
    for (int i = 0; i < n; i++)
    {
        char c;cin>>c;
        s[i]=c-'0';
    }
    int lst=-1;
    for (int i = 0; i < n; i++)
    {
        if(s[i]){
            if(i-lst==2){
                cout<<"NO\n";
                return;
            }
            lst=i;
        }
    }
    if(n-lst==2){
        cout<<"NO\n";
        return;
    }
    vector<int>ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i]=i+1;
    }
    lst=-1;
    for (int i = 0; i < n; i++)
    {
        if(s[i]){
            reverse(ans.begin()+lst+1,ans.begin()+i);
            lst=i;
        }
    }
    reverse(ans.begin()+lst+1,ans.end());
    cout<<"YES\n";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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