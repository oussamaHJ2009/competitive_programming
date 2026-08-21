#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q; if(!(cin>>N>>Q)) return 0;
    vector<int> a(N);
    for(int i=0;i<N;++i) cin>>a[i];
    const int B=20;
    vector<int> cnt(B,0), x(B,0);
    for(int v: a){
        for(int b=0;b<B;++b) if(v>>b & 1){
            cnt[b]++; x[b] ^= v;
        }
    }
    auto get_ans = [&](){
        int best = 0;
        for(int b=0;b<B;++b) if(cnt[b]>0){
            int cur = cnt[b] - (x[b]==0);
            best = max(best, cur);
        }
        return best;
    };
    cout<<get_ans()<<"\n";
    for(int qi=0; qi<Q; ++qi){
        int pos,val; cin>>pos>>val; --pos;
        int old = a[pos];
        if(old != val){
            for(int b=0;b<B;++b){
                if(old>>b & 1){ cnt[b]--; x[b] ^= old; }
                if(val>>b & 1){ cnt[b]++; x[b] ^= val; }
            }
            a[pos]=val;
        }
        cout<<get_ans()<<"\n";
    }
    return 0;
}
