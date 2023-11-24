#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long powm(long long x, long long n) {
    long long ans = 1;

    while (n > 0) {
        if ((n & 1) == 1) {
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        n >>= 1;
    }

    return ans;
}

int main() {
    long long N, K;
    cin >> N >> K;

    if (N == 1) {
        cout << K << endl;
    } else {
        cout << K * (K - 1) % MOD * powm(K - 2, N - 2) % MOD << endl;
    }

    return 0;
}
