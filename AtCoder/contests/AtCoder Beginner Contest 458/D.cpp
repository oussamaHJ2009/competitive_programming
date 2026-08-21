#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int X,Q;
    cin>>X>>Q;
    std::priority_queue<ll,vector<ll>, greater<ll>> r;
    std::priority_queue<ll> l;
    int mid=X;
    int x,y;
    cin>>x>>y;
    vector<int>s{x,y,X};
    sort(s.begin(),s.end());
    mid=s[1];
    cout<<mid<<'\n';
    l.push(s[0]);
    r.push(s[2]);
    
    for (int q = 1; q < Q; q++)
    {
        ll a,b;
        cin>>a>>b;
        ll A=min(a,b);
        ll B=max(a,b);
        if(mid >= A && mid <= B){
            l.push(A);
            r.push(B);
        }
        else if(mid>=B){
            l.push(A);
            r.push(mid);
            ll i=l.top();
            l.pop();
            l.push(min(i,B));
            mid=max(B,i);
        }
        else if(mid<=A){
            r.push(B);
            l.push(mid);
            ll i=r.top();
            r.pop();
            r.push(max(i,A));
            mid=min(A,i);
        }
        cout<<mid<<"\n";
    }
    

    return 0;

}