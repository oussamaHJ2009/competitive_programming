// problem link: https://codeforces.com/problemset/problem/2237/E
// authored by suc human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n;
    cin >> n;
    vector<int> suc(n), b(n);
    vector<int> id(n, -1);
    int cc_cnt = 0;
    for (int i = 0; i < n; i++)
        cin >> suc[i], suc[i]--;
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i] += (b[i] < 0 ? 0 : -1);
    vector<vector<int>> S;
    for (int i = 0; i < n; i++)
    {
        if (id[i] == -1)
        {
            vector<int> cyc;
            int cur = i;
            while (id[cur] == -1)
            {
                id[cur] = cc_cnt;
                cyc.push_back(cur);
                cur = suc[cur];
            }
            S.push_back(cyc);
            cc_cnt++;
        }
    }
    vector<bool>left(cc_cnt,true);
    vector<int> c(n,-1);
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1 && c[i]!=-1)
            continue;
        if (S[id[i]].size() != S[id[b[i]]].size())
        {
            cout << "NO" << '\n';
            return;
        }
        int m = S[id[i]].size();
        int j1 = 0, j2 = 0;
        while (S[id[i]][j1] != i)
            j1 = (j1 + 1) % m;
        while (S[id[b[i]]][j2] != b[i])
            j2 = (j2 + 1) % m;
        for (int nb = 0; nb < m; nb++)
        {
            if (b[S[id[i]][j1]] != S[id[b[i]]][j2] && b[S[id[i]][j1]] != -1)
            {
                cout << "NO\n";
                return;
            }
            c[S[id[i]][j1]] = S[id[b[i]]][j2];
            j1 = (j1 + 1) % m;
            j2 = (j2 + 1) % m;
        }
        left[id[b[i]]]=false;
    }

    for (int i = 0; i < n; i++)
    {
        if(c[i]!=-1)continue;
        if(left[id[i]]){
            for(auto x:S[id[i]]){
                c[x] = x;
            }
        }else{

        }
    }
    

    for(int i=0;i<n;i++)cerr<<c[i]<<' ';
    cerr<<'\n';
    vector<bool>fnd(n,false);
    for (int i = 0; i < n; i++)
    {
        if(fnd[c[i]]){
            cout<<"NO\n";
            return;
        }
        if(c[i]!=-1)fnd[c[i]]=1;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        cout<<c[i]<<' ';
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}