#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 8-neighborhood directional arrays
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    if (!(cin >> H >> W)) return 0;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    // dist[i][j] stores the shortest 8-directional distance to an "engine" cell
    // Initialize with -1 (unvisited)
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;

    // Step 1: Identify the "engines"
    // An engine cell is any cell that has at least one neighbor of the opposite color.
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            bool is_engine = false;
            for (int i = 0; i < 8; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                    if (grid[r][c] != grid[nr][nc]) {
                        is_engine = true;
                        break;
                    }
                }
            }
            if (is_engine) {
                dist[r][c] = 0;
                q.push({r, c});
            }
        }
    }

    // Step 2: Multi-source BFS to propagate distances across the grid
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    // Step 3: Determine final state at step 10^100 (an even power)
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            // If it never reaches an engine, it means the component was isolated 
            // (e.g., all black or all white). All black turns all white instantly and stays white.
            if (dist[r][c] == -1) {
                grid[r][c] = '.'; 
            } else {
                // If the distance to the closest engine is even, it preserves its state relative to the engine.
                // If odd, it flips.
                if (dist[r][c] % 2 != 0) {
                    grid[r][c] = (grid[r][c] == '#') ? '.' : '#';
                }
            }
        }
    }

    // Output the final grid
    for (int i = 0; i < H; ++i) {
        cout << grid[i] << "\n";
    }

    return 0;
}