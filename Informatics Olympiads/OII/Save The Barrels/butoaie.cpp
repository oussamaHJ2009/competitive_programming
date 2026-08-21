/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NB:
1.not thinking about bs
2.not considering the P-Q trick
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// constraints
#define MAXN 200000

// input data
int N, K, Q, P;
vector<int> V;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin>>N>>K;
    cin>>P>>Q;
    V.resize(N);
    for(int i=0; i<N; i++)
        cin>>V[i];

    // insert your code here
    ll ans = 0;
    
    ll mx = max(P,Q), mn = min(P,Q);
    ll mx_cnt = (P>Q ? K:N-K);
    ll mn_cnt = (P<=Q ? K:N-K);
    ll lo=(*max_element(V.begin(),V.end())+mx-1)/mx, hi=(*max_element(V.begin(),V.end())+mn-1)/mn;
    while (lo<=hi)
    {
        ll mid = lo+(hi-lo)/2;
        ll need=0;
        int cnt=0;
        for (int i=0;i<N;i++)
        {
            ll rem=max(0LL,V[i]-mid*mn);
            need+=(rem+mx-mn-1)/(mx-mn);
        }
        if(need<=mx_cnt*mid){
            hi = mid-1;
            ans = mid;
        }else{
            lo = mid+1;
        }
    }
    
    cout<<ans<<endl; // print the result
    return 0;
}
