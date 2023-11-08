#include <iostream>
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

// 階乗, 階乗の逆元、
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int N;
    cin >> N;
    COMinit();

    for (int k = 1; k <= N; k++) {
        long long cnt = 0;
        for (int a = 1; a <= (N / k) + 1; a++) {
            cnt = (cnt + COM(N - (k - 1) * (a - 1), a)) % MOD;
        }
        cout << cnt << endl;
    }
    return 0;
}
