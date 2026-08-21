#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> S;
vector<vector<vector<int>>>col;
int cur_col=0;
void dfs(int i,int j, int k){
    if(i<0 || j<0 || i>N-1 || j>M-1)return;
    if(col[i][j][k]!=-1)return;
    col[i][j][k]=cur_col;
    if(S[i][j]=='\\'){
        if(k==2||k==0)dfs(i,j,k+1);
        else dfs(i,j,k-1);
    }else{
        if(k==0){dfs(i,j,3);}
        if(k==1){dfs(i,j,2);}
        if(k==2){dfs(i,j,1);}
        if(k==3){dfs(i,j,0);}
    }
    if(k==0){dfs(i,j-1,2);}
    if(k==1){dfs(i+1,j,3);}
    if(k==2){dfs(i,j+1,0);}
    if(k==3){dfs(i-1,j,1);}
}

int main() {
//  ifstream cin("input1.txt");
//  ofstream cout("output.txt");

    cin >> N >> M;
    S.resize(N);
    for (int i=0; i<N; i++)
        cin >> S[i];

    col.assign(N,vector<vector<int>>(M,vector<int>(4,-1)));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if(col[i][j][k]==-1){
                    dfs(i,j,k);
                    cur_col++;
                }
            }   
        }   
    }

    cout << cur_col << endl;
    return 0;
}
