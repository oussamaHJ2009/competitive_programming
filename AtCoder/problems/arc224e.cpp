// problem link: https://atcoder.jp/contests/arc224/tasks/arc224_e
// authored by a human (i guess?)

#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    int cnt = 0;
    auto pop = [&](int n)
    {
        for (int i = 0; i < n; i++)
        {
            st.pop();
            cnt++;
        }
    };
    for (auto c : s)
    {
        if (c == 'A')
            st.push(c);
        else if (st.empty())
            continue;
        if (c == 'B')
        {
            while (!st.empty() && st.top() == 'B')
                pop(2);
            if (!st.empty())
                st.push(c);
        }
        if (c == 'C')
        {
            while (!st.empty() && st.top()=='A')
                pop(1);
            if(!st.empty()){
                pop(2);
                cnt++;
            }
        }
    }
    while (!st.empty())
        pop(1);

    cout << s.size() - cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}