/*
*created: 2026-08-09 at 17:41:00
*problem: B. Domino Tiles, link: https://codeforces.com/contest/2256/problem/B
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int ev=-1,od=-1;
    for(int i=0;i<n;i+=2)if(s[i]!='?'){ev=i;break;}
    for(int i=1;i<n;i+=2)if(s[i]!='?'){od=i;break;}
    char chr;
    if(ev!=-1){
        chr=s[ev];
        for(int i=ev;i<n;i+=2){
            if(s[i]=='?')s[i]=chr;
            else if(s[i]!=chr){
                cout<<"0\n";
                return;
            }
            chr = 1-(chr-'0')+'0';
        }
        chr=s[ev];
        for(int i=ev;i>=0;i-=2){
            if(s[i]=='?')s[i]=chr;
            else if(s[i]!=chr){
                cout<<"0\n";
                return;
            }
            chr = 1-(chr-'0')+'0';
        }
    }
    if(od!=-1){
        chr=s[od];
        for(int i=od;i<n;i+=2){
            if(s[i]=='?')s[i]=chr;
            else if(s[i]!=chr){
                cout<<"0\n";
                return;
            }
            chr = 1-(chr-'0')+'0';
        }chr=s[od];

        for(int i=od;i>=0;i-=2){
            if(s[i]=='?')s[i]=chr;
            else if(s[i]!=chr){
                cout<<"0\n";
                return;
            }
            chr = 1-(chr-'0')+'0';
        }
    }

    int ans=1;
    if(ev==-1)ans*=2;
    if(od==-1)ans*=2;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}