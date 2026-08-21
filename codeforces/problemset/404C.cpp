#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int d;
    vector<vector<int>> cnt(n);
    vector<int> adj(n,0);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        cnt[d].push_back(i);
    }
    if (cnt[0].size() > 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    map<pair<int, int>, bool> used;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < cnt[i].size(); j++)
        {
            if(cnt[i-1].empty()){
                cout<<-1<<'\n';
                return 0;
            }
            if (adj[cnt[i][j]] < k && adj[cnt[i - 1][j % cnt[i - 1].size()]]< k)
            {
                if (!used[{cnt[i - 1][j % cnt[i - 1].size()],cnt[i][j]}] || !used[{cnt[i][j], cnt[i - 1][j % cnt[i - 1].size()]}]){
                    adj[cnt[i][j]]++;
                    adj[cnt[i - 1][j % cnt[i - 1].size()]]++;
                    ans.push_back({cnt[i][j], cnt[i - 1][j % cnt[i - 1].size()]});
                }
            }
            else
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout<<ans.size()<<'\n';
    for (auto [a,b]:ans)
    {
        cout<<a+1<<' '<<b+1<<'\n';
    }
    

    return 0;
}