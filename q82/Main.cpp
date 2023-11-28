#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

unsigned long long ulpow(unsigned long long x, unsigned long long n) {
    unsigned long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long long sigma(unsigned long long l, unsigned long long r, int e) {
    long long rr = (r % MOD * (r + 1) % MOD) % MOD;
    long long ll = (l % MOD * (l - 1) % MOD) % MOD;
    return (rr - ll + MOD) % MOD * modinv(2, MOD) * e % MOD;
}

int main() {
    unsigned long long L, R;
    cin >> L >> R;

    unsigned long long answer = 0;
    for (int i = 1; i <= 19; i++) {
        unsigned long long l = max(L, ulpow(10, i - 1));
        unsigned long long r = min(R, ulpow(10, i) - 1);

        if (l > r) {
            continue;
        }

        answer += sigma(l, r, i);
        answer %= MOD;
    }

    cout << answer << endl;
    return 0;
}
