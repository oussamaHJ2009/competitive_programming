#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M,D;
    cin>>N>>D>>M;
    vector<int>J(N+1);
    vector<vector<int>>P(N+1);
    for (int i = 0; i < M; i++)
    {
        int x;
        cin>>x;
        J[x]++;
        P[x].push_back(i+1);
    }
    int lo=1;int hi=M;
    int mid;
    int ans=0;
    while (lo<=hi)
    {
        mid = lo+(hi-lo)/2;
        bool ok=true;
        queue<pair<int,int>>q;
        for (int i = 1; i <= N; i++)
        {
            if(J[i])q.push({J[i],i});
            int left=mid;
            if(!q.empty()&&i-D>q.front().second)ok=false;
            while(!q.empty()&&q.front().first<=left)left-=q.front().first,q.pop();
            if(!q.empty()&&q.front().first>left)q.front().first-=left;
        }
        
        if(ok){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans;
    queue<int>what;
    for (int i = 1; i <= N; i++)
    {
        cout<<"\n";
        for (auto sd:P[i])
        {
            what.push(sd);
        }
        for (int i = 0; i < ans && !what.empty(); i++)
        {
            cout<<what.front()<<" ";
            what.pop();
        }
        cout<<0;
    }
    
    
    return 0;

}