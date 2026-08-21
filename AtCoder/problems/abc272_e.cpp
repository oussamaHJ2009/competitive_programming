#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin>>N>>M;
    vector<int>A(N);
    vector<vector<int>>vals(M+1);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    for (int i = 0; i < N; i++)
    {
        if(A[i]>N)continue;
        int lo = (A[i]<0 ? (i-A[i])/(i+1) : 1);
        int hi = min(M, (N-A[i])/(i+1));
        for (int j = lo; j <= hi; j++)
        {
            vals[j].push_back(A[i]+(j*(i+1)));
        }
    }
    for (int i = 1; i <= M; i++)
    {
        int sz = vals[i].size();
        vector<bool>E(sz+1);
        for (int j:vals[i])
        {
            if(j<sz)E[j]=true;
        }
        
        int res=0;
        while(E[res])res++;
        cout<<res<<endl;
    }
    

    return 0;

}