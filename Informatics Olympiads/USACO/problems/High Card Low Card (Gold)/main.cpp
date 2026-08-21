#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 100005;

bool elsie[MAXN];
int els[MAXN], bes[MAXN],cnt[MAXN];

void solve() {
    int N;
    cin>>N;
    fill(elsie, elsie + 2 * N + 1, false);
    fill(cnt, cnt + 2 * N + 1, 0);
    for(int i=0;i<N;i++){
        cin>>els[i];
        elsie[els[i]]=true;
    }
    int idx=0;
    for (int i = 1; i <= 2*N; i++)
    {
        if(!elsie[i])bes[idx++]=i;
    }
    sort(els,els+(N/2));
    sort(els+(N/2), els+N);
    for (int i = N/2; i < 2*N; i++)
    {
        cnt[bes[i]]++;
    }
    for (int i = 2*N-1; i >=0; i--)
    {
        cnt[i]+=cnt[i+1];
    }
    int lst=0;
    int ans=0;
    for (int i = N/2 - 1; i >= 0; i--)
    {
        if(cnt[els[i]]>lst){
            ans++;
            lst++;
        }
    }

    fill(cnt,cnt+2*N+1,0);
    for(int i=0;i<N/2;i++){
        cnt[bes[i]]++;
    }

    for (int i = 1; i <= 2*N; i++)
    {
        cnt[i]+=cnt[i-1];
    }
    lst=0;
    for (int i = N/2; i < N; i++)
    {
        if(cnt[els[i]]>lst){
            lst++;
            ans++;
        }
    }
    cout<<ans;
}

int main() {
    setIO("cardgame");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}