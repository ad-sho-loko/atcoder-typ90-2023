#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, P, Q;
    cin >> N >> P >> Q;
    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long answer = 0;
    for (int i = 0; i < N - 4; i++) {
        for (int j = i + 1; j < N - 3; j++) {
            for (int k = j + 1; k < N - 2; k++) {
                for (int l = k + 1; l < N - 1; l++) {
                    for (int m = l + 1; m < N; m++) {
                        auto p = (((((A[i] * A[j]) % P) * A[k] % P) * A[l] % P) * A[m] % P);
                        if (p == Q) {
                            answer++;
                        }
                    }
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}