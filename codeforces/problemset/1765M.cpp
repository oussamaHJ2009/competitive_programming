#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a = 1, b = n-1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (lcm(i, n - i) < lcm(a, b))
                {
                    a = i;
                    b = n - i;
                }
                if (lcm(n / i, n - (n / i)) < lcm(a, b))
                {
                    a = n / i;
                    b = n - (n / i);
                }
            }
        }
        cout << a << " " << b << "\n";
    }

    return 0;
}