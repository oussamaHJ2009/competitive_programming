#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

struct w{
    int a,b,i;
};

bool cmp(w f, w s){
    if(f.a==s.a){
        return f.b>s.b;
    }
    return f.a<s.a;
}

void solve() {
    int n;
    cin>>n;
    vector<w>p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].a>>p[i].b;
        p[i].i=i;
    }
    
    sort(p.begin(),p.end(),cmp);
    vector<bool>S(n,true);
    int last=0;
    for (int i = 1; i < n; i++)
    {
        if(p[i].b<=p[last].b)S[p[i].i]=false;
        else last=i;
    }
    vector<int>res;
    for (int i = 0; i < n; i++)
    {
        if(S[i])res.push_back(i+1);
    }
    cout<<res.size()<<'\n';
    for (auto x:res)
    {
        cout<<x<<" ";
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}