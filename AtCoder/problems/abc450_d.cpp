#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    deque<int> q;
    for (auto &it : A){
        cin >> it;
        it%=K;
    }
    sort(A.begin(),A.end());
    for (auto x:A)
    {
        q.push_back(x);
    }
    
    int ans=q.back()-q.front();
    for (int i = 0; i < N; i++)
    {
        q.push_back(q.front()+K);
        q.pop_front();
        ans=min(ans,q.back()-q.front());
    }
    cout<<ans;

    return 0;
}