#include<bits/stdc++.h>
using namespace std;
int main() {
    auto trash = freopen("input.txt", "w", stdout);
    // 1. Obtain a random seed from the hardware
    random_device rd;
    
    // 2. Initialize the Mersenne Twister engine with the seed
    mt19937 gen(rd());
    
    // 3. Define the inclusive range [min, max]
    uniform_int_distribution<int> distrib(1, 10);
    
    // 4. Generate the random number
    int N = distrib(gen);
    uniform_int_distribution<int> node(1, N);
    cout<<N<<'\n';
    
    map<pair<int,int>,bool>used;
    for (int i = 0; i < N-1; i++)
    {
        int u=node(gen),v=node(gen);
        while(u==v || used[{u,v}])v=node(gen);
        used[{u,v}]=true;
        used[{v,u}]=true;
        cout<<u<<' '<<v<<'\n';
    }
    
    
    
    return 0;
}
