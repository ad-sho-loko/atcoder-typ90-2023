#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long answer = 0;
    for (int i = 0; i < (1 << N); i++) {
        long long target_bit = 0;
        long long count = 0;

        for (int j = 0; j < N; j++) {
            if ((i >> j) & 1) {
                target_bit |= A[j];
                count++;
            }
        }

        long long free_bit = 0;
        for (int j = 0; j < D; j++) {
            if (((target_bit >> j) & 1) == 0) {
                free_bit++;
            }
        }

        if (count % 2 == 0) {
            answer += (1LL << free_bit);
        } else {
            answer -= (1LL << free_bit);
        }
    }

    cout << answer << endl;
    return 0;
}
