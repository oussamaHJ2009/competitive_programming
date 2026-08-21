#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        vector<int>ans;
        for (auto i:a)
        {
            if(i%6==0)ans.push_back(i);
        }
        for (auto i:a)
        {
            if(i%2==0 && i%3!=0)ans.push_back(i);
        }
        for (auto i:a)
        {
            if(i%3!=0 && i%2!=0)ans.push_back(i);
        }
        for (auto i:a)
        {
            if(i%3==0 && i%2!=0)ans.push_back(i);
        }
        for (auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;

}