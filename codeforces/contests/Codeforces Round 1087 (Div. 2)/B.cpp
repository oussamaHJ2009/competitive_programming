#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i){
            int gt=0, lt=0;
            for(int j=i+1;j<n;++j){
                if(a[j]>a[i]) ++gt;
                else if(a[j]<a[i]) ++lt;
            }
            cout<<max(gt,lt);
            if(i+1<n) cout<<' ';
        }
        cout<<"\n";
    }
    return 0;
}
