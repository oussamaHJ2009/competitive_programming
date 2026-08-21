#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int>a1,b1;
        int ca1=0,ca0=0,cb1=0,cb0=0;
        for (int i = 0; i < n; i++)
        {
            ca0+=a[i]=='0';
            if(a[i]=='1'){
                ca1++;
                a1.push_back(i);
            }
            cb0+=b[i]=='0';
            if(b[i]=='1'){
                cb1++;
                b1.push_back(i);
            }
        }
        if(ca1!=cb1 || ca0!=cb0){
            cout<<-1<<'\n';
            continue;
        }
        int ans=0;
        for (int i = 0; i < ca1; i++)
        {
            if(a1[i]!=b1[i])ans++;
        }
        cout<<ans<<'\n';
    }
    


}