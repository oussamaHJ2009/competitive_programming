#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd (long long l ,long long r) {
    return l + rng() % ( r - l + 1) ;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n=rnd(1,5);
    cout<<n<<'\n';
    string k="sh";
    for(int i=0;i<n;i++){
        int len=rnd(1,6);
        for(int i=0;i<len;i++){
            cout<<k[rnd(0,1)];
        }
        cout<<'\n';
    }

    return 0;
}