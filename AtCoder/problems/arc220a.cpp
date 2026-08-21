//problem link: https://atcoder.jp/contests/arc220/tasks/arc220_a
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    if(n==2||n==3||n==5){
        cout<<"No\n";
        return;
    }
    deque<int>q;
    if(n%3==1){
        q={1};
    }else if(n%3==0){
        q={2,2,2,3,3,6};
    }else{
        q={2,2,3,3,3,3,6,6};
    }
    while (q.size()<n)
    {
        int c=q.front();
        q.pop_front();
        for(int i=0;i<4;i++)q.push_back(2*c);
    }
    sort(q.begin(),q.end());
    cout<<"Yes\n";
    for(auto x:q){
        cout<<x<<' ';
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}