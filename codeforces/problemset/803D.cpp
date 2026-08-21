#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin>>k;
    cin.ignore();
    string s;
    getline(cin,s,'\n');
    int n=s.size();
    vector<int>w;
    int W=0;
    int len=0;
    for (int i = 0; i < n; i++)
    {
        len++;
        if(s[i]==' '||s[i]=='-'||i==n-1){
            w.push_back(len);
            len=0;
            W++;
        }
    }
    int lo=1,hi=n;
    int ans=W;
    while (lo<=hi)
    {
        int mid = lo+(hi-lo)/2;
        int cur=0;
        int cnt=0;
        bool ok=true;
        for (auto x:w)
        {
            if(x>mid)ok=false;
            if(cur+x>mid){
                cnt++;
                cur=x;
            }
            else{
                cur+=x;
            }
        }
        if(cur)cnt++;
        if(cnt<=k && ok){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;

    return 0;

}