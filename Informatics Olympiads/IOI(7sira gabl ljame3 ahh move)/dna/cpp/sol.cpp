#include "dna.h"
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <algorithm>

using namespace std;

// pref[i][u][v] stores counts of transition (u -> v) in substring [0, i-1]
vector<array<array<int, 3>, 3>> pref;

int get_id(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    return 2; // 'T'
}

void init(string a, string b) {
    int n = a.size();
    pref.assign(n + 1, {{{0}}});

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        pref[i + 1][get_id(a[i])][get_id(b[i])]++;
    }
}

int get_distance(int x, int y) {
    int c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = pref[y + 1][i][j] - pref[x][i][j];
        }
    }

    // 1. Feasibility Check: Row sum (count in string A) must equal Column sum (count in string B)
    for (int i = 0; i < 3; i++) {
        int count_A = c[i][0] + c[i][1] + c[i][2];
        int count_B = c[0][i] + c[1][i] + c[2][i];
        if (count_A != count_B) return -1;
    }

    // 2. Direct 2-cycle swaps (A <-> C, A <-> T, C <-> T)
    int two_cycles = min(c[0][1], c[1][0]) 
                   + min(c[0][2], c[2][0]) 
                   + min(c[1][2], c[2][1]);

    // 3. 3-cycle swaps: Remaining unmatched pairs form 3-cycles, taking 2 swaps each
    int three_cycles = abs(c[0][1] - c[1][0]);

    return two_cycles + 2 * three_cycles;
}