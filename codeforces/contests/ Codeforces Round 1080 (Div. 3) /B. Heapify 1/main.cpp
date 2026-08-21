#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        bool ans = true;
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            while (j % 2 == 0)
            {
                j /= 2;
            }
            bool b = false;
            for (j; j <= n; j *= 2)
            {
                if(j <= n){
                    if(a[i] == j)b = true;
                }
            }
            if(b == false)ans = false;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}