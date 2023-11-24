#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> C;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

int dfs(int sr, int sc, int nr, int nc, vector<vector<bool>>& visited, int cost) {
    if (sr == nr && sc == nc && visited[sr][sc]) {
        return cost;
    }

    visited[nr][nc] = true;

    int max_cost = -1;
    for (int i = 0; i < 4; i++) {
        int to_r = nr + dr[i];
        int to_c = nc + dc[i];
        if (to_r >= 0 && to_r < H && to_c >= 0 && to_c < W && C[to_r][to_c] == '.' &&
            (!visited[to_r][to_c] || (sr == to_r && sc == to_c))) {
            max_cost = max(max_cost, dfs(sr, sc, to_r, to_c, visited, cost + 1));
        }
    }

    visited[nr][nc] = false;
    return max_cost;
}

int main() {
    cin >> H >> W;
    C.resize(H);

    for (int i = 0; i < H; i++) {
        cin >> C[i];
    }

    int max_answer = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            vector<vector<bool>> visited(H, vector<bool>(W));
            max_answer = max(max_answer, dfs(i, j, i, j, visited, 0));
        }
    }

    cout << (max_answer <= 2 ? -1 : max_answer) << endl;
    return 0;
}
