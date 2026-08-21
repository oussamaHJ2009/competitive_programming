#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353
const ll INF = 1e18;

int hi(int i){
    return (i+1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin>>N;
    vector<ll>A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }

    vector<ll>pre1(N/2+1,-INF);
    vector<ll>pre2(N/2+1,-INF);
    vector<ll>cur(N/2+1,-INF);
    pre2[0]=0;
    pre1[0] = 0;
    pre1[1] = A[0];
    for (int i = 2; i <= N; i++)
    {
        int lo = max(0, N/2 - (N - i + 1) / 2);
        int hi = min(N/2, (i + 1) / 2);
        for (int j = lo; j <= hi; j++){
            cur[j] = pre1[j];
            if(j)cur[j]=max(cur[j],pre2[j-1]+A[i-1]);
        }
        for (int j = lo; j <= hi; j++)
        {
            pre2[j]=pre1[j];
            pre1[j]=cur[j];
        }
        
    }
    
    cout<<cur[N/2]<<endl;
    
    return 0;

}