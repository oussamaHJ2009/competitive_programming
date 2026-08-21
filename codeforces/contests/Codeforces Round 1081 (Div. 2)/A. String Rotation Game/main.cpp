#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<char> s(n);
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }
        int res = 0;
        vector<char>rot(n);
        for (int i = 0; i < n; i++)
        {
            int f = 0;
            for (int j = i + 1; j < n; j++)
            {
                rot[f] = s[j];
                f++;
            }
            for (int j = 0; j <= i; j++)
            {
                rot[f] = s[j];
                f++;
            }
            int cnt = 1;
            for (int j = 1; j < n; j++)
            {
                if(rot[j] != rot[j-1]){
                    cnt++;
                }
            }
            res = max(res, cnt);
            
        }
        cout<<res<<endl;

    }
    

    return 0;

}