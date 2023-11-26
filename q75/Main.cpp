#include <bits/stdc++.h>
using namespace std;

vector<long long> prime_factors(long long N) {
    long long rem = N;
    vector<long long> p;

    for (long long i = 2; i * i <= N; i++) {
        while (rem % i == 0) {
            rem /= i;
            p.push_back(i);
        }
    }

    if (rem != 1LL) {
        p.push_back(rem);
    }

    return p;
}

int main() {
    long long N;
    cin >> N;

    auto primes = prime_factors(N);
    long long answer;

    for (int k = 0; k < 20; k++) {
        if (primes.size() <= (1LL << k)) {
            answer = k;
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
