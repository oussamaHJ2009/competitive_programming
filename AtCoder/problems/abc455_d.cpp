#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,Q;
    cin>>N>>Q;
    vector<int>top(N,-1),bot(N,-1);
    for (int q = 0; q < Q; q++)
    {
        int c,p;
        cin>>c>>p;
        c--;p--;
        if(bot[c]!=-1)top[bot[c]]=-1;
        top[p]=c;
        bot[c]=p;
    }
    vector<int>ans(N,0);
    for (int i = 0; i < N; i++)
    {
        if(bot[i]==-1){
            int x=i;
            ans[i]=1;
            while (top[x]!=-1)
            {
                ans[i]++;
                x=top[x];
            }
            
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<ans[i]<<(i<N-1 ? " " : "\n");
    }
    

    return 0;

}