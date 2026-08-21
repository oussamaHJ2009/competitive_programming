#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,K;
    cin>>N>>K;
    vector<ll>x(N);
    vector<ll>y(N);
    vector<vector<bool>>ok(N,vector<bool>(N,true));
    for (int i = 0; i < N; i++)
    {
        cin>>x[i]>>y[i];
    }
    
    if(K==1){
        cout<<"Infinity"<<endl;
        return 0;
    }
    auto col = [&](int a, int b, int c){
        ll f1 = (x[b]-x[a])*(y[c]-y[a]);
        ll f2 = (y[b]-y[a])*(x[c]-x[a]);
        return (f1==f2);
    };
    ll ans=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if(ok[i][j]){
                int cnt = 2;
                vector<int>T;
                T.push_back(i);
                T.push_back(j);
                for (int k = j+1; k < N; k++)
                {
                    if(col(i,j,k)){
                        cnt++;
                        T.push_back(k);
                    }
                }
                if(cnt>=K){
                    ans++;
                    for (int ii = 0; ii < cnt; ii++)
                    {
                        for (int jj = ii+1; jj < cnt; jj++)
                        {
                            ok[T[ii]][T[jj]]=false;
                            ok[T[jj]][T[ii]]=false;
                        }
                        
                    }
                    
                }
            }
        }
        
    }
    cout<<ans<<endl;

    return 0;

}