#include <iostream>
using namespace std;

int H, W, sr, sc, tr, tc, mind = 100000;
bool G[1002][1002];
bool visited[1002][1002];

enum Dir { Top, Left, Right, Bottom, None };

void dfs(int nr, int nc, int cnt, Dir prevDir) {
    if (nr == tr && nc == tc) {
        mind = min(mind, cnt);
        return;
    }
    visited[nr][nc] = true;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    Dir dd[4] = {Left, Top, Right, Bottom};

    for (int i = 0; i < 4; i++) {
        int x = nr + dx[i];
        int y = nc + dy[i];
        if (G[x][y] && !visited[x][y]) {
            if (prevDir == dd[i]) {
                dfs(x, y, cnt, dd[i]);
            } else {
                dfs(x, y, cnt + 1, dd[i]);
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

    dfs(sr, sc, 0, None);
    cout << mind - 1 << endl;

    return 0;
}