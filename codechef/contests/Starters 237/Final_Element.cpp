#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int final_element = 0;
    int n_minus_1 = N - 1;

    for (int i = 0; i < N; i++) {
        if ((n_minus_1 & i) == i) {
            final_element ^= A[i];
        }
    }
    cout << final_element << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}