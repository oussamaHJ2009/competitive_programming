#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int, int> p;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            p[x] = i;
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        bool per = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = min(p[a[i]], i); j <= max(p[a[i]], i); j++)
            {
                if(a[i] != a[j]){
                    per = false;
                    break;
                }
            }
            
            
        }
        if(per){
            cout<<"Yes"<<endl;
        }else
        {
            cout<<"No"<<endl;
        }
        
    }
    
}