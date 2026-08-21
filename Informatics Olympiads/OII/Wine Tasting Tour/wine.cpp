/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NB:
1-ma fe9tech bfaset bs 3le 3ded illi as8r min sum yebde as8r X>=K bech nelou biha lsum illi bech n5tarou
2-bs 3le less:3ded illi < final_cost w b3d k-less yjini tertib heke l3ded m3e illi geddou w n3ml 2p w nlgah
3-integer overflow?????!!!!!?!?!?!?!?!?
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// input data
int N;
long long K;
vector<ll> V;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input1.txt");
//  ofstream cout("output.txt");

    cin >> N >> K;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // insert your code here
    int S = 0, E = 0;
    vector<ll>pref(N+1,0);
    for (int i = 1; i <= N; i++)
    {
        pref[i]=pref[i-1]+V[i-1];
    }
    ll lo = *min_element(V.begin(),V.end()), hi = pref[N];
    ll best=pref[N];
    ll cnt=0;
    while (lo<=hi)
    {
        ll mid = lo+(hi-lo)/2;
        int l = 0;
        cnt=0;
        for (int r = 1; r <= N; r++)
        {
            while(pref[r]-pref[l]>mid && l<=r)l++;
            if(pref[r]-pref[l]<=mid)cnt+=r-l;
        }
        if(cnt>=K){
            hi = mid-1;
            best = mid;
        }else{
            lo = mid+1;
        }
    }
    int l = 0;
    ll less=0;
    for (int r = 1; r <= N; r++)
    {
        while(pref[r]-pref[l]>=best && l<=r)l++;
        if(pref[r]-pref[l]<best)less+=r-l;
    }
    ll rnk = 0;
    for ( E = 0; E < N; E++)
    {
        while (pref[E+1]-pref[S]>best && E>=S)S++;
        if(pref[E+1]-pref[S]==best)rnk++;
        if(rnk==K-less)break;
    }
    
    // print the result
    cout << S << ' ' << E << endl;
    return 0;
}
