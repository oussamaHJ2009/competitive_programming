//problem link: https://codeforces.com/contest/1556/problem/D
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int qry(int i,int j,string p){
    cout<<p<<' '<<i<<' '<<j<<'\n';
    cout.flush();
    int ret;
    cin>>ret;
    if(ret==-1)exit(0);
    return ret;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    ll o12=qry(1,2,"or");
    ll a12=qry(1,2,"and");
    ll o23=qry(2,3,"or");
    ll a23=qry(2,3,"and");
    ll o13=qry(1,3,"or");
    ll a13=qry(1,3,"and");
    ll s12=(o12^a12) + 2*a12;
    ll s23=(o23^a23) + 2*a23;
    ll s13=(o13^a13) + 2*a13;
    a[0]=(s12+s13+s23)/2-s23;
    a[2]=(s12+s13+s23)/2-s12;
    a[1]=(s12+s13+s23)/2-s13;
    for (int i = 3; i < n; i++)
    {
        ll andd = qry(1,i+1,"and");
        ll orz = qry(1,i+1,"or");
        a[i]=(andd^orz)+2*andd - a[0];
    }
    sort(a.begin(),a.end());
    cout<<"finish "<<a[k-1]<<'\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}