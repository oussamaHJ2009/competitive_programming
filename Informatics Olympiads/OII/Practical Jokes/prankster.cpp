#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> S;

int main() {
  //ifstream cin("input1.txt");
  //ofstream cout("output.txt");

    cin >> N;
    S.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    vector<int>D(N);
    D[0]=S[0];
    for (int i = 1; i < N; i++)
    {
        D[i]=(S[i]-S[i-1]+3)%3;
    }
    
    vector<int>cnt(3,0);
    for (int i = 0; i < N; i++)
    {
        cnt[D[i]]+=(D[i]>0);
    }
    int ans=min(cnt[2],cnt[1]);
    cnt[2]-=ans;
    cnt[1]-=ans;
    ans+=(max(cnt[1],cnt[2])/3)*2+max(cnt[1],cnt[2])%3;

    cout<<ans<<endl;
    return 0;
}
