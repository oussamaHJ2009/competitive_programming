#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> robots(n); for (auto &x: robots) cin >> x;

        vector<int> lava(m); for (auto &x: lava) cin >> x;

        vector<bool> dead(n); 
        map<int, vector<int>> death_locations;

        string instructions;
        cin >> instructions;

        sort(lava.begin(), lava.end());

        for (int i = 0; i < n; i++) {
            if (lava[0] < robots[i]) {
                int left_dist = robots[i] - (*(lower_bound(lava.begin(), lava.end(), robots[i]) - 1));
                death_locations[-left_dist].push_back(i);
            }
            if (lava[m-1] > robots[i]) {
                int right_dist = *lower_bound(lava.begin(), lava.end(), robots[i]) - robots[i];
                death_locations[right_dist].push_back(i);
            }
            
        }

        int current_pos = 0;
        int alive = n;

        for (auto &x: instructions) {
            if (x == 'L') current_pos--;
            else current_pos++;

            for (int i: death_locations[current_pos]) {
                
                if (dead[i]) continue;
                dead[i] = true;
                alive--;
            }
            death_locations[current_pos].clear();
            cout << alive << " ";
        }

        cout << "\n";
    }
}