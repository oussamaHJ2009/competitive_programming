#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans="";
    map<char,string>as;
    as['0']="";
    as['1']="";
    as['2']="2";
    as['3']="3";
    as['4']="223";
    as['5']="5";
    as['6']="53";
    as['7']="7";
    as['8']="2227";
    as['9']="7332";

    for (auto x:s)
    {
        ans+=as[x];
    }
    sort(ans.rbegin(),ans.rend());
    cout<<ans<<endl;


    return 0;

}