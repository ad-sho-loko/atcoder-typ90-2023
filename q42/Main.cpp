#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1000000007;

int main() {
    int K;
    cin >> K;

    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(K + 1);
    dp[0] = 1;

    for (int i = 1; i <= 9; i++) {
        for (int j = i; j > 0; j--) {
            dp[i] += dp[i - j];
        }
    }

    for (int i = 10; i <= K; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i] += dp[i - j];
            if (dp[i] >= MOD) {
                dp[i] -= MOD;
            }
        }
    }

    cout << dp[K] << endl;
    return 0;
}