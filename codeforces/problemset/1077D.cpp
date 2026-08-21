#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353
const int MAXN=2*1e5+1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int>s(n);
    vector<int>cnt(MAXN,0);
    for(auto &it:s){
        cin>>it;
        cnt[it]++;
    }
    int lo=1,hi=n;
    vector<int>t;
    int best=1;
    while (lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        int c=0;
        for (int i = 0; i < MAXN; i++)
        {
            c+=cnt[i]/mid;
        }
        if(c>=k){
            lo=mid+1;
            best=mid;
        }else{
            hi=mid-1;
        }
    }
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < cnt[i]/best; j++)
        {
            t.push_back(i);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout<<t[i]<<' ';
    }
    

    return 0;

}