#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    long long N, L;
    long long dp[1000000];

    cin >> N >> L;

    dp[1] = 1;
    dp[L] = 1;
    for (int i = 1; i <= 100000; i++) {
        if (dp[i] > 0) {
            dp[i + 1] += dp[i] % MOD;
            dp[i + L] += dp[i] % MOD;
        }
    }

    cout << dp[N] % MOD << endl;
    return 0;
}
