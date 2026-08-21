#include "dna.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> cnt;
vector<vector<int>> D;

void init(string a, string b)
{
	int n = a.size();
	auto id = [&](char c)
	{
		if (c == 'A')
			return 0;
		else if (c == 'C')
			return 1;
		else
			return 2;
	};
	auto get = [&](char c1, char c2)
	{
		if (c1 == 'A' && c2 == 'C')
			return 0;
		if (c1 == 'C' && c2 == 'A')
			return 1;
		if (c1 == 'A' && c2 == 'T')
			return 2;
		if (c1 == 'T' && c2 == 'A')
			return 3;
		if (c1 == 'C' && c2 == 'T')
			return 4;
		if (c1 == 'T' && c2 == 'C')
			return 5;
		return -1;
	};
	cnt.assign(2, vector<vector<int>>(n + 1, vector<int>(3, 0)));
	D.assign(n + 1, vector<int>(6, 0));
	for (int i = 0; i < n; i++)
	{
		cnt[0][i + 1] = cnt[0][i];
		cnt[1][i + 1] = cnt[1][i];

		cnt[0][i + 1][id(a[i])]++;
		cnt[1][i + 1][id(b[i])]++;

		D[i + 1] = D[i];
		if (a[i] != b[i])
			D[i + 1][get(a[i], b[i])]++;
	}
}

int get_distance(int x, int y)
{
	bool a = (cnt[0][y + 1][0] - cnt[0][x][0]) != (cnt[1][y + 1][0] - cnt[1][x][0]),
		 b = (cnt[0][y + 1][1] - cnt[0][x][1]) != (cnt[1][y + 1][1] - cnt[1][x][1]),
		 c = (cnt[0][y + 1][2] - cnt[0][x][2]) != (cnt[1][y + 1][2] - cnt[1][x][2]);
	if (a || b || c)
		return -1;

	int m1 = min(D[y + 1][0] - D[x][0], D[y + 1][1] - D[x][1]),
		m2 = min(D[y + 1][2] - D[x][2], D[y + 1][3] - D[x][3]),
		m3 = min(D[y + 1][4] - D[x][4], D[y + 1][5] - D[x][5]),
		a1 = max(D[y + 1][0] - D[x][0], D[y + 1][1] - D[x][1]) - m1,
		a2 = max(D[y + 1][2] - D[x][2], D[y + 1][3] - D[x][3]) - m2,
		a3 = max(D[y + 1][4] - D[x][4], D[y + 1][5] - D[x][5]) - m3;
	return m1 + m2 + m3 + a1 + a2 + a3 - ((a1 + a2 + a3) / 3);
}
