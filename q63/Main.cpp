#include <bits/stdc++.h>
using namespace std;

// vector
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> P(H, vector<int>(W));
    vector<vector<int>> Cnt(1 << H, vector<int>(H * W + 1));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> P[i][j];
        }
    }

    for (int i = 1; i < 1 << H; i++) {
        vector<int> rows;
        for (int j = 0; j < H; j++) {
            if (((i >> j) & 1) == 1) {
                rows.push_back(j);
            }
        }

        for (int j = 0; j < W; j++) {
            auto isAllSame = true;
            auto p = P[rows[0]][j];
            auto cnt = 1;

            for (int r = 1; r < rows.size(); r++) {
                if (P[rows[r]][j] != p) {
                    isAllSame = false;
                    break;
                }
                cnt++;
            }

            if (isAllSame) {
                Cnt[i][p] += cnt;
            }
        }
    }

    auto answer = -1;
    for (int i = 0; i < (1 << H); i++) {
        for (int j = 0; j <= H * W; j++) {
            answer = max(answer, Cnt[i][j]);
        }
    }

    cout << answer << endl;
    return 0;
}
