#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ll p, q;
        cin>>p>>q;
        int g = min(p / 2, q / 3);
        bool bob = false;
        while (g)
        {
            if(p - g * 2 == q - g * 3) bob = true;
            g--;
        }
        
        if(bob){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }
    
}