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
    vector<int>C(10);
    string ans="";
    int mn = 1;
    for (int i = 1; i < 10; i++)
    {
        cin>>C[i];
        if(C[mn]>=C[i])mn=i;
    }
    for (int i = 0; i < N/C[mn]; i++)
    {
        ans+=mn+'0';
    }
    int cnt=C[mn] * (N/C[mn]);
    int cur=0;
    for (int i = 9; i > mn; i--)
    {
        while (cnt-C[mn]+C[i]<=N)
        {
            cnt+=C[i]-C[mn];
            ans[cur]='0'+i;
            cur++;
        }
    }
    
    cout<<ans<<endl;

    return 0;

}