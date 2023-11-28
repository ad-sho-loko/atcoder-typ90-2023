#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long N) {
    vector<long long> res;

    for (long long i = 1; i * i <= N; ++i) {
        if (N % i != 0) continue;
        res.push_back(i);
        if (N / i != i) res.push_back(N / i);
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {
    long long K;
    cin >> K;
    auto d = divisors(K);

    long long answer = 0;

    for (int i = 0; i < d.size(); i++) {
        for (int j = i; j < d.size(); j++) {
            long long a = d[i];
            long long b = d[j];

            if ((K / a) < b) continue;
            if (K % (a * b) != 0LL) continue;
            long long c = K / (a * b);
            if (b <= c) answer += 1;
        }
    }

    cout << answer << endl;
    return 0;
}
