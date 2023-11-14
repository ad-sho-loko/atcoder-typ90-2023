#include <deque>
#include <iostream>
#include <tuple>
using namespace std;

int H, W, sr, sc, tr, tc, inf = 100000;
bool G[1002][1002];
int cost[1002][1002][4];
enum Dir { Left = 0, Top = 1, Right = 2, Bottom = 3 };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
Dir dd[4] = {Left, Top, Right, Bottom};

void dfs(int nr, int nc, int cnt, Dir prevDir) {
    cost[nr][nc][prevDir] = cnt;

    if (nr == tr && nc == tc) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int r = nr + dy[i];
        int c = nc + dx[i];
        int cst = cost[r][c][dd[i]];
        if (G[r][c] && (cst > cnt)) {
            if (prevDir == dd[i]) {
                dfs(r, c, cnt, dd[i]);
            } else {
                dfs(r, c, cnt + 1, dd[i]);
            }
        }
    }
}

void bfs(int sr, int sc) {
    deque<tuple<int, int, Dir>> q;
    for (int i = 0; i < 4; i++) {
        cost[sr][sc][i] = 0;
        q.push_back({sr, sc, dd[i]});
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        int r = get<0>(p);
        int c = get<1>(p);
        Dir d = get<2>(p);

        for (int i = 0; i < 4; i++) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if (G[nr][nc] && cost[r][c][d] < cost[nr][nc][dd[i]]) {
                cost[nr][nc][dd[i]] = cost[r][c][d] + (d == dd[i] ? 0 : 1);
                q.push_back({nr, nc, dd[i]});
            }
        }
    }
}

int main() {
    cin >> H >> W >> sr >> sc >> tr >> tc;

    string s;
    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == '.') {
                G[i + 1][j + 1] = true;
            }
        }
    }

    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            for (int k = 0; k < 4; k++) {
                cost[i][j][k] = inf;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        // dfs(sr, sc, 0, dd[i]);
        bfs(sr, sc);
    }

    int answer = inf;
    for (int i = 0; i < 4; i++) {
        answer = min(answer, cost[tr][tc][i]);
    }

    cout << answer << endl;
    return 0;
}