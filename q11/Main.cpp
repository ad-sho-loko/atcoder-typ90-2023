#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

void debug(vector<tuple<int, int, long long>> &tuples) {
    int i = 0;
    for (auto t : tuples) {
        cout << "(" << i << ") " << get<0>(t) << " " << get<1>(t) << " "
             << get<2>(t) << endl;
        i++;
    }
}

int main() {
    int N;
    cin >> N;
    vector<tuple<int, int, long long>> W(N);
    long long dp[N + 1][5001];

    for (int i = 0; i < N; i++) {
        int D, C;
        long long S;
        cin >> D >> C >> S;
        W[i] = {D, C, S};
    }
    sort(W.begin(), W.end());

    for (int i = 0; i < N; i++) {
        auto d = get<0>(W[i]);
        auto c = get<1>(W[i]);
        auto s = get<2>(W[i]);

        for (int j = 0; j <= 5000; j++) {
            if (j + c <= d) {
                // 現在のj日目からc日使うことが可能(締切日d日以内に完了できる）であれば仕事iを実行する
                dp[i + 1][j + c] = max(dp[i + 1][j + c], dp[i][j] + s);
            }

            // 仕事iを実行しない場合
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    long long maxs = 0;
    for (int i = 0; i <= 5000; i++) {
        maxs = max(dp[N][i], maxs);
    }
    cout << maxs << endl;

    return 0;
}