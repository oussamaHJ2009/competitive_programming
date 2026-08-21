/*
lowkey a tuff problem took me whole day only to get wrong.
didn't PIE shit
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    vector<int> A(N + 1, 0), B(N + 1, 0), C(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        A[i] = (S[i - 1] == 'A') + A[i - 1];
        B[i] = (S[i - 1] == 'B') + B[i - 1];
        C[i] = (S[i - 1] == 'C') + C[i - 1];
    }

    map<int, ll> AB, AC, BC;
    map<pair<int, int>, ll> ABC;

    for (int i = 0; i <= N; i++)
    {
        AB[A[i] - B[i]]++;
        BC[B[i] - C[i]]++;
        AC[A[i] - C[i]]++;
        ABC[{A[i] - B[i], A[i] - C[i]}]++;
    }
    ll ans = 0;
    for (int i = 0; i <= N; i++)
    {
        ll I = AB[A[i] - B[i]] + BC[B[i] - C[i]] + AC[A[i] - C[i]] - 2 * ABC[{A[i] - B[i], A[i] - C[i]}];
        ans += N - I + 1;
    }
    cout << ans / 2 << "\n";

    return 0;
}