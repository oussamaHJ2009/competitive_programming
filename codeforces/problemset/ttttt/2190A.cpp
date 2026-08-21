#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            char c;
            cin>>c;
            a[i] = c - '0';
        }
        vector<int> ans;
        int m = 0;
        ans.assign(a.begin(), a.end());
        sort(ans.begin(), ans.end());
        bool alice = false;
        for (int i = 0; i < n; i++)
        {
            if(a[i] != ans[i])
            {
                alice = true;
                m++;
            }
        }
        if(alice){
            cout<<"Alice"<<endl<<m<<endl;
            for (int i = 0; i < n; i++)
            {
                if(a[i] != ans[i])cout<<i+1<<' ';
            }
        }else cout<<"Bob";
        cout<<endl;
    }
}