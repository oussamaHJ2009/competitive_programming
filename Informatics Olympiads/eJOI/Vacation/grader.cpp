#include "vacation.h"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    cout << plan_vacation(n, l, r, k) << endl;
}