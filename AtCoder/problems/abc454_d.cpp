#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

string f(string s){
        string c="";
        for(auto x:s)
        {
            c+=x;
            if(c.size()>=4 && c.substr(c.size()-4,4)=="(xx)"){
                c.erase(c.size()-4,4);
                c+="xx";
            }
        }
        return c;
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
        string A, B;
        cin >> A >> B;
        if(f(A)==f(B))cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}