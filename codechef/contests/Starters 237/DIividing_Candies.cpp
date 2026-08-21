#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int N,X;
        cin>>N>>X;
        vector<int>A(N);
        int ans=0;
        for (int i = 0; i < N; i++)
        {
            cin>>A[i];
            if(A[i]%X==0)ans=max(ans,A[i]);
        }
        cout<<ans<<endl;
    }

    return 0;

}