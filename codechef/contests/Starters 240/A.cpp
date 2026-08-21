#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int A,B,X,Y;
    cin>>X>>Y>>A>>B;
    if(X>A)cout<<"Alice";
    else if(X<A)cout<<"Bob";
    else{
        if(Y>=B)cout<<"Alice";
        else cout<<"Bob";
    }   

}