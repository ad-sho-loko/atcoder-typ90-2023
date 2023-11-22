#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, Q;
    cin >> N >> Q;
    vector<long long> A(N + 1), L(Q + 1), R(Q + 1), V(Q + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i] >> V[i];
    }

    vector<long long> D(N);
    long long answer = 0;
    for (int i = 1; i <= N - 1; i++) {
        D[i] = A[i + 1] - A[i];
        answer += abs(D[i]);
    }

    for (int i = 1; i <= Q; i++) {
        auto before = abs(D[L[i] - 1]) + abs(D[R[i]]);

        if (L[i] >= 2) {
            D[L[i] - 1] += V[i];
        }

        if (R[i] <= N - 1) {
            D[R[i]] -= V[i];
        }

        auto after = abs(D[L[i] - 1]) + abs(D[R[i]]);

        answer += after - before;
        cout << answer << endl;
    }

    return 0;
}