#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> X, Y;

void ternary_search() {
    auto fx = [&](long long x) {
        long long d = 0;
        for (int i = 0; i < N; i++) {
            d += abs(x - X[i]);
        }
        return d;
    };

    auto fy = [&](long long y) {
        long long d = 0;
        for (int i = 0; i < N; i++) {
            d += abs(y - Y[i]);
        }
        return d;
    };

    // x
    long long low = -1000000001, high = 1000000001;
    int cnt = 500;
    long long minx = powl(10, 18);

    while (cnt--) {
        long long c1 = (low * 2 + high) / 3;
        long long c2 = (low + high * 2) / 3;
        long long fc1 = fx(c1);
        long long fc2 = fx(c2);
        minx = min(minx, min(fc1, fc2));

        if (fx(c1) > fx(c2)) {
            low = c1;
        } else {
            high = c2;
        }
    }

    // y
    low = -1000000001, high = 1000000001;
    cnt = 500;
    long long miny = powl(10, 18);

    while (cnt--) {
        long long c1 = (low * 2 + high) / 3;
        long long c2 = (low + high * 2) / 3;
        long long fc1 = fy(c1);
        long long fc2 = fy(c2);
        miny = min(miny, min(fc1, fc2));

        if (fy(c1) > fy(c2)) {
            low = c1;
        } else {
            high = c2;
        }
    }

    cout << minx + miny << endl;
}

int main() {
    cin >> N;
    X.resize(N);
    Y.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    nth_element(X.begin(), X.begin() + N / 2, X.end());
    nth_element(Y.begin(), Y.begin() + N / 2, Y.end());

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += abs(X[i] - X[N / 2]);
        ans += abs(Y[i] - Y[N / 2]);
    }

    cout << ans << endl;
    return 0;
}
