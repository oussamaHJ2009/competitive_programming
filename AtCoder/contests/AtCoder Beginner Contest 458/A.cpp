#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    string S;
    cin>>S;
    int N;
    cin>>N;
    string ans=S.substr(N,S.size()-2*N);
    cout<<ans<<'\n';

    return 0;

}