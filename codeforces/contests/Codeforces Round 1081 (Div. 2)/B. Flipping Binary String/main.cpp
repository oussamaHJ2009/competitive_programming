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
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            char c;
            cin>>c;
            s[i] = c - '0';
        }
        int k = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            k+=s[i];
            if(s[i])ans.push_back(i+1);
        }
        if(k % 2 == 1){
            cout<< -1<<endl;
        }else{
            cout<<k;
            if(k>0)cout<<endl;
            for (int i = 0; i < k; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            
        }
        
    }
    

    return 0;

}