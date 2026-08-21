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
        int n; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int l = 0, r = n - 1;
        int mx = n, mn = 1;
        while (l<r)
        {
            if(a[l] == mx){
                l++;
                mx--;
            }
            else if(a[r] == mx){
                r--;
                mx--;
            }
            else if(a[l] == mn){
                l++;
                mn++;
            }
            else if(a[r] == mn){
                r--;
                mn++;
            }
            else{
                break;
            }
        }
        if(l == r)cout<< -1<<endl;
        else cout<<l+1<<" "<<r+1<<endl;
        
    }
    
    

    return 0;

}