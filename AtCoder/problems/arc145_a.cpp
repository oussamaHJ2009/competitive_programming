#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin>>N;
    string S;
    cin>>S;
    if((S[0]!='A'||S[N-1]!='B') && S!="BA")cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
