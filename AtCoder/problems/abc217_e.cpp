#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int Q;
    cin>>Q;
    deque<int>q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (Q--)
    {
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            q.push_back(x);
        }else if(t==2){
            if(!pq.empty()){
                cout<<pq.top()<<endl;
                pq.pop();
            }else{
                cout<<q.front()<<endl;
                q.pop_front();
            }
        }else{
            while (!q.empty())
            {
                pq.push(q.front());
                q.pop_front();
            }
        }
    }
    

    return 0;

}