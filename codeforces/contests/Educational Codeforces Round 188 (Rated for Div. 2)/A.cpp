#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=1;
        for (int i = 0; i < n; i++)
        {
            if(s[i]!='R')break;
            else cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;

}