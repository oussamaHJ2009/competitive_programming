/*
*created: 2026-08-17 at 13:56:59
*problem: C. Robot Collisions, link: https://codeforces.com/problemset/problem/1525/C
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct rob{
    int pos,id,dir;
    bool operator<(rob a){return pos<a.pos;}
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<rob>x(n);
    vector<rob>robo[2]{{},{}};
    for(int i=0;i<n;i++){
        cin>>x[i].pos;
        x[i].id=i;
    }
    for(int i=0;i<n;i++){
        char c;cin>>c;
        x[i].dir = (c=='R');
        robo[x[i].pos & 1].push_back(x[i]);
    }
    
    vector<int>ans(n,-1);
    for(int cur = 0;cur<2;cur++){
        sort(robo[cur].begin(),robo[cur].end());
        stack<rob>st;
        deque<rob>L,R;
        for(int i = 0; i < robo[cur].size();i++){
            if(robo[cur][i].dir){
                st.push(robo[cur][i]);
            }
            else if(!st.empty()){
                rob t = st.top();st.pop();
                ans[t.id] = (ans[robo[cur][i].id] = abs(t.pos-robo[cur][i].pos)/2);
            }else{
                L.push_back(robo[cur][i]);
            }
        }
        while(!st.empty()){
            R.push_back(st.top());
            st.pop();
        }
        
        while(R.size()>1){
            rob r1 = R.front();R.pop_front();
            rob r2 = R.front();R.pop_front();
            ans[r1.id] = (ans[r2.id] = m - r1.pos + abs(r1.pos - r2.pos)/2);
        }

        while(L.size()>1){
            rob l1 = L.front();L.pop_front();
            rob l2 = L.front();L.pop_front();
            ans[l1.id] = (ans[l2.id] = l1.pos + abs(l1.pos - l2.pos)/2);
        }

        if(!R.empty() && !L.empty()){
            auto l = L.front();
            auto r = R.front();
            ans[l.id] = (ans[r.id] = max(m-r.pos,l.pos) + (m - abs(m-r.pos-l.pos))/2);
        }
    }
    //mela 7ela ??????!!!!!

    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}



// could've used -x trick