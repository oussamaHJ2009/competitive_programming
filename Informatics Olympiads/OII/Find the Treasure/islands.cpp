#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define MAXN 1000

int R, C;
int M[MAXN][MAXN];
int cur_col=0;

vector<vector<int>>col;
void flood(int i, int j){
    if(i < 0 || j < 0 || j >C-1 || i>R-1)return;
    if(col[i][j]!=-1 || !M[i][j])return;
    col[i][j]=cur_col;
    flood(i+1,j);
    flood(i,j+1);
    flood(i,j-1);
    flood(i-1,j);
}

int main() {

//  freopen("input20.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2==scanf("%d %d", &R, &C));
    for(int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            assert(scanf("%d", &M[i][j]));
        }
    }
    col.assign(R,vector<int>(C,-1));
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(col[i][j]==-1 and M[i][j]){
                flood(i,j);
                cur_col++;
            }
        }
    }
    vector<bool>changed(cur_col,false);
    int cnt=cur_col;
    for (int i = 0; i < R; i++)
    {
        if(M[i][0]){
            if(!changed[col[i][0]]){
                cnt--;
                changed[col[i][0]]=true;
            }
        }
        if(M[i][C-1]){
            if(!changed[col[i][C-1]]){
                cnt--;
                changed[col[i][C-1]]=true;
            }
        }
    }
    for (int i = 0; i < C; i++)
    {
        if(M[0][i]){
            if(!changed[col[0][i]]){
                cnt--;
                changed[col[0][i]]=true;
            }
        }
        if(M[R-1][i]){
            if(!changed[col[R-1][i]]){
                cnt--;
                changed[col[R-1][i]]=true;
            }
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}
