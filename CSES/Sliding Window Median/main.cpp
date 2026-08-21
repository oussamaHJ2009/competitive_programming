#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==1){
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        return;
    }
    multiset<int> L, R;
    vector<int>ans;
    for(int i=0;i<k;i++){
        R.insert(a[i]);
    }
    while(L.size() < (k+1)/2){
        L.insert(*R.begin());
        R.erase(R.begin());
    }
    ans.push_back(*L.rbegin());
    for(int i=k;i<n;i++){
        if(a[i-k]>=*R.begin()){
            R.erase(R.lower_bound(a[i-k]));
        }else L.erase(L.lower_bound(a[i-k]));
        if(!R.empty() && a[i]>=*R.begin()){
            R.insert(a[i]);
        }else L.insert(a[i]);
        while (L.size()<(k+1)/2)
        {
            L.insert(*R.begin());
            R.erase(R.begin());
        }
        
        while (L.size()>(k+1)/2)
        {
            R.insert(*L.rbegin());
            L.erase(prev(L.end()));
        }
        ans.push_back(*L.rbegin());
    }

    for(auto x:ans){
        cout<<x<<' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}