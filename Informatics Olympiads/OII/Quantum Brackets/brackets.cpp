#include <bits/stdc++.h>
using namespace std;

int N, K, T, i, t;
vector<int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    assert(cin >> T);
    for (t = 0; t < T; t++)
    {
        assert(cin >> N >> K);
        P.resize(N);
        for (i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }
        vector<stack<int>> last(K);
        vector<int> cnt(N + 1, 0);
        for (int i = 0; i < N; i++) {
            cnt[i + 1] = cnt[i];
            if (!last[P[i]].empty() && cnt[last[P[i]].top() + 1] == cnt[i + 1]) {
                last[P[i]].pop();
                cnt[i + 1]--;
            }
            else {
                last[P[i]].push(i);
                cnt[i + 1]++;
            }
        }
        if (cnt[N]) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}