#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> vec(n); for (auto &x: vec) cin >> x;
        vector<int> original_vec(n); for (int i = 0; i < n; i++) original_vec[i] = vec[i];
        vector<int> last_element_update(n, -1);
        int last_reset = -1;
        int reset_count = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;

            if (last_element_update[a] < last_reset) vec[a] = original_vec[a];
            vec[a] += b;
            if (vec[a] > k) {
                last_reset = i;
                reset_count++;
                vec[a] = original_vec[a];
            }
            last_element_update[a] = i;
        }

        ll sum = 0;
        for (int i = 0; i < n; i++) {

            if (last_element_update[i] < last_reset) vec[i] = original_vec[i];
            cout << vec[i] << " ";
        }
        cout << "\n";


    }
}