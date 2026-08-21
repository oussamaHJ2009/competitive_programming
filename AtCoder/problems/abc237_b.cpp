#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int h,w;
    cin>>h>>w;
    vector<vector<int>>A(h,vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin>>A[i][j];
        }
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            cout<<A[j][i]<<" ";
        }
        cout<<endl;
    }
    

    return 0;

}