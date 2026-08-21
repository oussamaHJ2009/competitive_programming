#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        ll ab = lcm(a, b), abc = lcm(lcm(a, b), c), ac = lcm(a, c), bc = lcm(b, c);
        ll al3 = ((m / ab) + (m / ac) - (2 * (m / abc)));
        ll bo3 = ((m / ab) + (m / bc) - (2 * (m / abc)));
        ll ca3 = ((m / bc) + (m / ac) - (2 * (m / abc)));
        ll al = 2 * (m / abc) + (3 * al3) + 6 * ((m / a) - al3 - (m / abc));
        ll bo = 2 * (m / abc) + (3 * bo3) + 6 * ((m / b) - bo3 - (m / abc));
        ll ca = 2 * (m / abc) + (3 * ca3) + 6 * ((m / c) - ca3 - (m / abc));
        cout<<al<<" "<<bo<<" "<<ca<<" "<<endl;
    }

    return 0;
}