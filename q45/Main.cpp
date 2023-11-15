#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

int main() {
    int K, N;
    cin >> N >> K;
    vector<long long> X(N), Y(N);
    vector<vector<long long>> D(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    // (1) すべての各二点間の距離を計算
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] =
                (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
        }
    }

    // (2) bitの立て方によって表した点の組合わせにおける最大距離を算出する
    // 例)
    // 00101 -> 点1と点3の集合。最大距離はD[0][2]。
    // 10101 -> 点1,3,5の集合。
    // 最大距離はmax(D[0][0], D[2][2], D[4][4], D[0][2],D[0][4], D[2][4])。
    vector<long long> costs(1 << N);
    for (int i = 1; i < 1 << N; i++) {
        auto points = vector<int>(0);
        for (int j = 0; j < N; j++) {
            if (((i >> j) & 1) == 1) {
                points.push_back(j);
            }
        }

        if (points.size() > 1) {
            for (int ii = 0; ii < points.size() - 1; ii++) {
                for (int jj = 1; jj < points.size(); jj++) {
                    costs[i] = max(costs[i], D[ii][jj]);
                }
            }
        }
    }

    // (3) 動的計画法で答えである最小値を探す
    // dp[現在作成したグループ数][すでに選んだ点の集合]でdp[K][2^N-1]が答えになるように。
    vector<vector<long long>> dp(K + 1, vector<long long>(1 << N, 1LL << 62));
    dp[0][0] = 0;
    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j < 1 << N; ++j) {
            for (int k = j; k != 0; k = (k - 1) & j) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], costs[k]));
            }
        }
    }

    cout << dp[K][(1 << N) - 1] << endl;
    return 0;
}
