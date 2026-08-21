#include "dreaming.h"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<pair<ll, ll>>>adj;
vector<ll>d;
vector<bool>vis;

void rem(ll u){
    vis[u]=1;
    d[u]=0;
    for(auto [v,w]:adj[u]){
        if(!vis[v])rem(v);
    }
}

void dist(ll u,ll p,ll &mx){
    if(p==-1)d[u]=0;
    for(auto [v,w]:adj[u]){
        if(v!=p){
            d[v] = d[u] + w;
            if(d[mx]<d[v])mx=v;
            dist(v,u, mx);
        }
    }
}

bool path(ll e, ll u, ll p, vector<ll>&pth){
    if(u==e)return true;
    for(auto [v,w]:adj[u]){
        if(v==p)continue;
        if(path(e,v,u,pth)){
            pth.push_back(w);
            return true;
        }
    }
    return false;
}

vector<ll> get(ll st){
    
    ll a=st;
    dist(st,-1,a);
    ll b=a;
    dist(a,-1,b);
    vector<ll>ret;
    path(b,a,-1,ret);
    rem(st);
    return ret;
}


int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    
    //assigning stuff
    adj.assign(N,vector<pair<ll,ll>>());
    d.assign(N,0);
    vis.assign(N,0);

    for(ll i=0;i<M;i++){
        adj[A[i]].push_back({B[i], T[i]});
        adj[B[i]].push_back({A[i], T[i]});
    }

    vector<pair<ll,ll>>diams;
    ll res=0;
    for(ll i=0;i<N;i++){
        if(!vis[i]){
            auto W = get(i);
            ll S = accumulate(W.begin(),W.end(),0);
            ll Dlen = S, Rlen = S;
            for(auto we:W){
                S-=we;
                Rlen = min(Rlen, max(Dlen-S,S));
            }
            diams.push_back({Rlen,Dlen});
            res=max(res,Dlen);
        }
    }
    sort(diams.begin(),diams.end(),greater<pair<ll,ll>>());
    if(diams.size()>1)res=max(res, diams[0].first + diams[1].first + L);
    if(diams.size()>2)res=max(res, diams[1].first + diams[2].first + 2*L);
    return res;
}