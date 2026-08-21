#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>P(N);
        vector<bool>M(N,false);
        int cnt=0;
        for (int i = 0; i < N; i++)
        {
            cin>>P[i];
            P[i]--;
        }
        for (int i = 0; i < N; i++)
        {
            if(M[i])break;
            if(P[i]<=i)cnt++;
            else{
                if(N-P[i]<=1){
                    cnt++;
                    M[P[i]]=true;
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;

}