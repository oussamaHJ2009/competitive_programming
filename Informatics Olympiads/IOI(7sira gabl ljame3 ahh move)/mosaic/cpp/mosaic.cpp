#include "mosaic.h"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> mosaic(vector<int> X, vector<int> Y,
                  vector<int> T, vector<int> B,
                  vector<int> L, vector<int> R)
{
  int Q = (int)T.size();
  int N = (int)X.size();

  vector<ll> C(Q);

  vector<vector<int>> G(N);
  for (int i = 0; i < N; i++)
    if (i < 3)
      G[i].assign(N, 0);
    else
      G[i].assign(3, 0);
  for (int i = 0; i < N; i++)
    G[0][i] = X[i], G[i][0] = Y[i];
  for (int i = 1; i < min(N,3); i++)
    for (int j = 1; j < N; j++)
      G[i][j] = 1 ^ (G[i][j - 1] | G[i - 1][j]);
  for (int i = 1; i < N; i++)
    for (int j = 1; j < 3; j++)
      G[i][j] = 1 ^ (G[i][j - 1] | G[i - 1][j]);

  vector<vector<ll>> pre(N + 1);
  for (int i = 0; i <= N; i++)
    if (i < 4)
      pre[i].assign(N + 1, 0);
    else
      pre[i].assign(4, 0);
  for (int i = 1; i <= N; i++)
  {
    int M = (i < 4 ? N : 3);
    for (int j = 1; j <= M; j++)
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + G[i - 1][j - 1] - pre[i - 1][j - 1];
  }

  vector<ll> P1(2 * N + 5, 0), P2(2 * N + 5, 0); // might need to add 5 ????
  if (N > 2)
  {
    int idx = 1;
    for (int i = N - 1; i > 1; i--)
      P1[idx] = G[i][2] + P1[idx - 1], idx++;

    for (int i = 3; i < N; i++)
      P1[idx] = G[2][i] + P1[idx - 1], idx++;

    for (int i = 1; i < 2 * N; i++)
      P2[i] = P2[i - 1] + P1[i];
  }
  auto prop = [&](int i, int j)
  {
    return N - 2 + j - i;
  };
  auto del = [&](int &t, int &b, int &l, int &r) -> ll
  {
    ll S = 0;
    if (t < 2)
    {
      int lc = min(max(2, l), r + 1);
      S += pre[min(b, 1) + 1][r + 1] - pre[min(b, 1) + 1][lc] - pre[t][r + 1] + pre[t][lc];
    }
    if (l < 2)
      S += pre[b + 1][min(r, 1) + 1] - pre[t][min(r, 1) + 1] - pre[b + 1][l] + pre[t][l];
    l = max(l, 2);
    t = max(t, 2);
    return S;
  };

  auto get = [&](int t, int b, int l, int r) -> ll
  {
    if (l > r || t > b)
      return 0LL;
    int TR = max(prop(t, r), 0),
        BR = max(prop(b, r) - 1, 0),
        TL = max(prop(t, l) - 1, 0),
        BL = max(0, prop(b, l) - 2);
    return P2[TR] - P2[BR] - P2[TL] + P2[BL];
  };

  for (int k = 0; k < Q; k++)
  {
    C[k] = del(T[k], B[k], L[k], R[k]);
    if (N > 2)
      C[k] += get(T[k], B[k], L[k], R[k]);
  }

  return C;
}