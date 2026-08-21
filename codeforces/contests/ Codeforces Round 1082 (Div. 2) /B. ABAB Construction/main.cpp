#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

void solve()
{
    int n;
    cin >> n;
    string x;
    cin >> x;
    bool ans = false;
    char a = x[0], b = x[1];
    for (int f = 0; f < 2; f++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool fl = true;
            if (a == '?')
            {
                x[0] = 'a' + f;
            }
            if (b == '?')
            {
                x[1] = 'a' + j;
            }

            if(n%2 == 1 && x[0] != 'a')fl = false;
            if(n%2 == 0 && x[0] == x[1])fl = false;
            for (int i = 0; i + 2 < n; i++)
            {
                if (x[i] == x[i + 1] && x[i] == x[i + 2] && x[i] != '?')
                {
                    fl = false;
                    break;
                }
            }
            for (int i = 0; i <= n - 3; i++)
            {
                if (x[i + 2] == '?' && x[i] != '?' && x[i + 1] != '?' && x[i] == x[i+1])
                {
                    x[i + 2] == 'a' ^ 'b' ^ x[i];
                }
            }
            int a = 0;
            int b =0;
            for (int k = 0; k < n; k++)
            {
                a+=x[k]=='a';
                b+=x[k]=='b';
            }
            if(fl && a <= (n+1)/2 && b <= n/2)ans=true;
        }
    }

    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
        solve();
    }

    return 0;
}