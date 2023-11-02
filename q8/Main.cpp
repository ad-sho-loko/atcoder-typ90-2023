#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1000000007;

int main() {
    int N;
    string S;
    cin >> N >> S;

    long long dp[N + 1][8];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i][j] = 0;
        }
        dp[i][0] = 1;
    }

    for (int j = 1; j < 8; j++) {
        for (int i = 1; i < N + 1; i++) {
            if (S[i - 1] == "atcoder"[j - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][7] % 1000000007 << endl;
    return 0;
}