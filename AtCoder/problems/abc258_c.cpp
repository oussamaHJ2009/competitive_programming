#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, Q;
    cin>>n>>Q;
    string s;
    cin>>s;
    int c = 0;
    while (Q--)
    {
        int x, q;
        cin>>q>>x;
        if(q==1){c+=x;c%=n;}
        if(q==2){
            cout<<s[(n-c+x-1)%n]<<endl;
        }
    }
    

    return 0;

}