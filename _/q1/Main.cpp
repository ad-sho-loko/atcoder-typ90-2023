#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll N, L, K;
vector<ll> A, Gap;

bool is_cuttable(ll target) {
    ll length = 0;
    auto k = K;

    for (auto g : Gap) {
        length += g;

        // 長さが目的の長さを超えれば貪欲法に切ってしまってもよい
        if (k > 0 && length >= target) {
            length = 0;
            k--;
        }
    }

    if (length < target) {
        return false;
    }

    return true;
}

int main() {
    cin >> N >> L >> K;
    A.resize(N);
    Gap.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    Gap[0] = A[0];
    for (int i = 1; i < N; i++) {
        Gap[i] = A[i] - A[i - 1];
    }
    Gap[N] = L - A[N - 1];

    ll left = -1, right = L;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        if (is_cuttable(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;
    return 0;
}
