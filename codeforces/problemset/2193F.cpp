#include <bits/stdc++.h>
 
#define F first
#define S second
#define ll long long
 
using namespace std;
 
int main()
{
    ll t;
    cin >> t;
    
    while( t -- )
    {
        ll n, ax, ay, bx, by;
        cin >> n >> ax >> ay >> bx >> by;
        vector <ll> x(n + 5), y(n + 5), dp[2];
        
        dp[0] = dp[1] = vector <ll> (n + 5, 0);
        map <ll, ll> mx, mn;
        
        mn[ax] = mx[ax] = ay;
        mn[bx] = mx[bx] = by;
        
        for( ll i = 0; i < n; i ++ ) cin >> x[i];
        for( ll i = 0; i < n; i ++ ) cin >> y[i];
        
        for( ll i = 0; i < n; i ++ )
        {
            if(!mx.count(x[i])) mx[x[i]] = y[i];
            else mx[x[i]] = max(mx[x[i]], y[i]);
            if(!mn.count(x[i])) mn[x[i]] = y[i];
            else mn[x[i]] = min(mn[x[i]], y[i]);
        }
        ll lst = ax, cnt = 0;
        
        for( auto i : mx )
        {
            if( i.F == ax )
            {
                dp[0][0] = dp[1][0] = 0;
                continue;
            }
            ll need = (i.F - lst) + (mx[i.F] - mn[i.F]);
            cnt ++;
            
            dp[0][cnt] = min(dp[0][cnt - 1] + abs(mx[i.F] - mn[lst]), dp[1][cnt - 1] + abs(mx[i.F] - mx[lst])) + need;
            dp[1][cnt] = min(dp[0][cnt - 1] + abs(mn[i.F] - mn[lst]), dp[1][cnt - 1] + abs(mn[i.F] - mx[lst])) + need;
            
            lst = i.F;
        }
        cout << dp[0][cnt] << '\n';
    }
}