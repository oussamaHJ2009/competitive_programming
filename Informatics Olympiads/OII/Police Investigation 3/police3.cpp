// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input1.txt");
//  ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> T(N+1);
    for (int i=0; i<N; i++)
        cin >> T[i];

    // insert your code here
    vector<int>dp(N+1);
    dp[0]=T[0];dp[1]=T[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i]=min(dp[i-1],dp[i-2])+T[i];
    }
    

    cout << dp[N] << endl; // print the result
    return 0;
}
