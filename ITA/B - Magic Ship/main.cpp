#include <bits/stdc++.h>
#define optimise ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vi vector<int> 
#define vl vector<long long> 
#define vii vector<pair<int,int>>
#define pb push_back
#define ll long long int
#define fi first
#define se second
long long MOD=1e9+7;
double PI=3.14159265359;
int arx[8]={1,1,0,-1,-1,-1, 0, 1};
int ary[8]={0,1,1, 1, 0,-1,-1,-1};
int main(){
    optimise;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        //FOR USACO:
    /*#ifndef ONLINE_JUDGE
        freopen("mountains.in", "r", stdin);
        freopen("mountains.out", "w", stdout);
    #endif*/
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    long long l,r;
    l = -10;
    r = 1e15;
    int n;
    cin>>n;
    string text;
    cin>>text;
    pair<ll,ll> tab[n];
    pair<ll,ll> cur = {0,0};
    for (int i = 0; i < n; ++i)
    {
        if(text[i]=='R') cur.fi++;
        if(text[i]=='L') cur.fi--;
        if(text[i]=='D') cur.se--;
        if(text[i]=='U') cur.se++;
        tab[i] = cur;
    }
    cout <<cur.fi<<" "<<cur.se<<endl;
    while(r-l>1){
        long long mid = (r+l)/2;
        pair<ll,ll> dis = {a+cur.fi*(mid/n),b+cur.se*(mid/n)};
        if(mid%n) dis.fi += tab[mid%n-1].fi;
        if(mid%n) dis.se += tab[mid%n-1].se;
        if(abs(dis.fi-x)+abs(dis.se-y) <= mid) r=mid;
        else l = mid;
    } 
    if(r>1ll*2*1e14) cout <<-1<<endl;
    else cout << r <<endl;
}
