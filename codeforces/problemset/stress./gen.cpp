#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono ::steady_clock ::now().time_since_epoch().count());

long long rnd(long long l, long long r)
{
    return l + rng() % (r - l + 1);
}

int main()
{
    for (int fr = 0; fr < 1; fr++)
    {
        int n = rnd(1, 5);
        vector<int> a(n), b(n);
        iota(a.begin(), a.end(), 1);
        shuffle(a.begin(), a.end(), rng);
        iota(b.begin(), b.end(), 1);
        shuffle(b.begin(), b.end(), rng);
        cout << n << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << ' ';
        }
        cout<<'\n'<<'\n';
    }
}