#include <iostream>
using namespace std;

int main() {
    int W, N, L, R;
    long long V;
    cin >> W >> N;
    long long dp[N + 1][W + 1];

    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> L >> R >> V;

        for (int l = L; l <= R; l++) {
            dp[i][l] = max(dp[i][l], V);
        }

        // 選ばない
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
        }

        // 選ぶ
        for (int w = 0; w <= W; w++) {
            if (dp[i - 1][w] != 0) {
                for (int l = L; l <= R; l++) {
                    if (w + l <= W) {
                        dp[i][w + l] = max(dp[i - 1][w] + V, dp[i][w + l]);
                    }
                }
            }
        }
    }

    long long maxv = -1;
    for (int i = 1; i <= N; i++) {
        if (dp[i][W] > 0) {
            maxv = max(maxv, dp[i][W]);
        }
    }

    cout << maxv << endl;
    return 0;
}