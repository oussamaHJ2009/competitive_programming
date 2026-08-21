#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,K;
    cin>>N>>K;
    cout<<max(N/2+1-K,0)<<endl;

    return 0;

}