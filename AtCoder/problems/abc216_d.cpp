#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<stack<int>> a(M);
    vector<int> cnt(N + 1, 0);
    vector<vector<int>> col_pos(N + 1);
    queue<int> nxt;
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            a[i].push(x);
            col_pos[x].push_back(i);
        }
        cnt[a[i].top()]++;
        if (cnt[a[i].top()] == 2)
        {
            nxt.push(a[i].top());
        }
    }
    int ball_cnt = N * 2;
    while (!nxt.empty())
    {
        int cur_col = nxt.front();
        nxt.pop();
        cnt[cur_col] = 0;
        a[col_pos[cur_col][0]].pop();
        a[col_pos[cur_col][1]].pop();
        ball_cnt -= 2;
        if (!a[col_pos[cur_col][0]].empty())
        {
            cnt[a[col_pos[cur_col][0]].top()]++;
            if (cnt[a[col_pos[cur_col][0]].top()] == 2)
            {
                nxt.push(a[col_pos[cur_col][0]].top());
            }
        }
        if (!a[col_pos[cur_col][1]].empty())
        {
            cnt[a[col_pos[cur_col][1]].top()]++;
            if (cnt[a[col_pos[cur_col][1]].top()] == 2)
            {
                nxt.push(a[col_pos[cur_col][1]].top());
            }
        }
        col_pos[cur_col].pop_back();
        col_pos[cur_col].pop_back();
    }

    if (ball_cnt == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}