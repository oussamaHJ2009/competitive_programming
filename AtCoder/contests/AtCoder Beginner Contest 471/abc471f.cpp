/*
*created: 2026-08-15 at 13:00:06
*problem: Concat (maximize), link: https://atcoder.jp/contests/abc471/tasks/abc471_f
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool cmp1(string s,string t){
    ll a = stoll(s), b=stoll(t);
    string x = s+t;
    string y = t+s;
    if(a==b){
        if(x==y)return s.size()>t.size();
        return x>y;
    }
    return a>b;
}

bool cmp2(string s,string t){
    ll a = stoll(s), b=stoll(t);
    string x = s+t;
    string y = t+s;
    if(x==y){
        return a>b;
    }
    return x>y;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp1);
    sort(a.begin(),a.begin()+k,cmp2);
    string str="";
    for(int i=0;i<k;i++){
        str += a[i];
    }
    bool pt=0;
    string ans="";
    for(auto c:str){
        if(c!='0')pt=1;
        if(pt)ans+=c;
    }
    if(ans=="")ans+='0';
    cout<<ans<<'\n';
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}