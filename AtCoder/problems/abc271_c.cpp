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

    int N;
    cin >> N;
    vector<int> a(N);
    vector<bool> cnt(N + 1);
    int sold = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] > N)sold++;
        else if (cnt[a[i]])sold++;
        else cnt[a[i]]=true;
    }
    int L = 1, R = N + 1;
    while (L < R)
    {
        while (sold > 1 || cnt[L])
        {
            if (!cnt[L])
            {
                sold -= 2;
                cnt[L]=true;
            }
            L++;
        }
        R--;
        if (cnt[R])
        {
            sold++;
            cnt[R] = false;
        }
    }
    cout<<L-1<<"\n";
    return 0;
}