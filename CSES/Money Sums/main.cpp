/*
----------------------------------------------------------------------------------------------------------------------------------
forgot to count if it is possible to sum=0 from i coins
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int>x(n);
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
        sum+=x[i];
    }
    set<int>ans;
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    dp[0][0]=true;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            dp[i][s]=dp[i-1][s];
            if(s-x[i-1]>=0){
                if(dp[i-1][s-x[i-1]]==true){
                    dp[i][s]=true;
                    ans.insert(s);
                }
            }
        }
    }

    cout<<ans.size()<<endl;
    for (auto a:ans)
    {
        cout<<a<<" ";
    }
    
    return 0;

}