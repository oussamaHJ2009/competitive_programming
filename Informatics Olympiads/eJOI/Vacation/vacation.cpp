#include "vacation.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int plan_vacation(int N, vector<int> L, vector<int> R, long long K)
{
    auto check = [&](ll x){
        vector<int>pts;
        for(int i=0;i<N;i++)pts.push_back(L[i]);
        for(int i=0;i<N;i++)pts.push_back(R[i] - x + 1);
        auto med = pts.begin() + N;
        nth_element(pts.begin(),med,pts.end());
        ll D=0;
        for(int i=0;i<N;i++){
            if(R[i] < *med + x - 1) D+=*med + x - 1 -R[i];
            if(L[i] > *med) D+= L[i] - *med;
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
    return ret;
}