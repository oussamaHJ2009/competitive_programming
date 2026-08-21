#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string S;
    cin>>S;
    int N=S.size();
    ll ans=0;
    for (int i = 0; i < N; i++)
    {
        if(S[i]=='C'){
            ans+=min(i,N-1-i)+1;
        }
    }
    cout<<ans<<'\n';


    return 0;

}