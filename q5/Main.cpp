#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1000000007;

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void slow() {
    long long N, B, K;
    cin >> N >> B >> K;
    vector<long long> C(K);
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(B));

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B; j++) {
            if (dp[i][j] == 0) {
                continue;
            }

            for (int k = 0; k < K; k++) {
                int m = ((C[k] * modpow(10, i, B)) % B + j) % B;
                dp[i + 1][m] += dp[i][j];
                if (dp[i + 1][m] >= MOD) {
                    dp[i + 1][m] -= MOD;
                }
            }
        }
    }

    // cout << dp << endl;
    cout << dp[N][0] << endl;
}

int main() {
    slow();
    return 0;
}
