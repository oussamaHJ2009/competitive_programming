#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long S = 0, sum_sq = 0, ones = 0;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            S += x;
            sum_sq += x * x;
            if(x == 1) ones++;
        }
        long long ans = (S*S - sum_sq)/2 + min(ones, (long long)(n-1));
        cout << ans << "\n";
    }
    return 0;
}