#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin>>n>>m;
    int ans = 0;
    while (n != m)
    {
        if(m > n){
            if(m % 2 == 1){
                m++;
                ans++;
            }
            else{
                m /= 2;
                ans++;
            }
        }
        else{
            m++;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}