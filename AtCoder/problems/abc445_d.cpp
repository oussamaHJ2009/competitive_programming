#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int H,W,N;
    cin >> H >> W >> N;
    vector<int>w(N),h(N);
    map<int,queue<int>>cnth,cntw;
    vector<pair<int,int>>cor(N);
    vector<bool>used(N,false);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i] >> w[i];
        cnth[h[i]].push(i);
        cntw[w[i]].push(i);
    }

    int curW=W,curH=H;
    while (curW>0 && curH>0)
    {
        //clear used ones
        while (!cnth[curH].empty())
        {
            if(!used[cnth[curH].front()])break;
            cnth[curH].pop();
        }
        while (!cntw[curW].empty())
        {
            if(!used[cntw[curW].front()])break;
            cntw[curW].pop();
        }
        if(!cnth[curH].empty()){
            int i=cnth[curH].front();
            cnth[curH].pop();
            used[i]=true;
            cor[i]={1+H-curH,1+W-curW};
            curW-=w[i];
        }
        else if(!cntw[curW].empty()){
            int i=cntw[curW].front();
            cntw[curW].pop();
            used[i]=true;
            cor[i]={1+H-curH,1+W-curW};
            curH-=h[i];
        }
    }
    

    for (auto [x, y] : cor)
    {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}