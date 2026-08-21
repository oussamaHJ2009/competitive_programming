#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    long long K;
    cin >> N >> K;
    vector<int> L(N);
    vector<int> R(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
    }

    
    
    auto check = [&](ll x){
        // for pts[N] used as a right end pt
        vector<int>pts;
        for(int i=0;i<N;i++)pts.push_back(L[i]);
        for(int i=0;i<N;i++)pts.push_back(R[i] - x + 1);
        sort(pts.begin(),pts.end());
        ll D=0;
        for(int i=0;i<N;i++){
            if(R[i] < pts[N] + x - 1) D+=pts[N] + x - 1 -R[i];
            if(L[i] > pts[N]) D+= L[i] - pts[N];
        }
        if(D<=K)return true;
        D=0;
        for(int i=0;i<N;i++){
            if(R[i] < pts[N - 1] + x - 1) D+=pts[N - 1] + x - 1 -R[i];
            if(L[i] > pts[N - 1]) D+= L[i] - pts[N - 1];
        }
        return D<=K;
    };
    
    
    int lo=0,hi=1e9;
    for(ll i=0;i<N;i++)hi=min(hi,R[i]-L[i]+1);
    int ret=0;
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        if(check(mid)){
            lo=mid+1;
            ret=mid;
        }else{
            hi = mid-1;
        }
    }
    cout<<ret<<'\n';
}