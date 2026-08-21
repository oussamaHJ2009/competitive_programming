/*
 *created: 2026-08-02 at 16:40:05
 *problem: Pro Exam Eligibility, link: https://atcoder.jp/contests/abc469/tasks/abc469_e
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld eps = 1e-15;

void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int>p(n+1,0);
    for(int i=0;i<n;i++)
        p[i+1]=p[i] + (s[i]=='o');
    
    auto check=[&](ld X){
        int l=0;
        ld mn=1e18;
        for(int r=1;r<=n;r++){
            while(p[r]-p[l]>=k){
                ld Al = p[l]-l*X;
                mn=min(mn,Al);
                l++;
            }
            ld Ar = p[r]-r*X;
            if(Ar>=mn && l>0)return true;
        }
        return false;
    };

    ld lo=0;ld hi = 1; ld mid;
    int c=0;
    while(hi-lo>=eps){
        c++;
        mid = (hi+lo)/2.0;
        if(check(mid)){
            lo=mid;
        }else hi=mid;
    }
    cout<<fixed<<setprecision(15)<<lo<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}