#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

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
        sort(a.begin(),a.end());
        int g=a[0];
        for (int i = 1; i < n; i++)
        {
            g=gcd(g,a[i]);
        }
        cout<<(*max_element(a.begin(),a.end()))/g<<'\n';
    }

    return 0;

}