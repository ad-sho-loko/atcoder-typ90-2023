#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }

    double answer = 0.0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            auto comb = 0;
            auto cnt = 0;
            for (int l = L[i]; l <= R[i]; l++) {
                for (int k = L[j]; k <= R[j]; k++) {
                    if (l > k) {
                        cnt++;
                    }
                    comb++;
                }
            }

            answer += double(cnt) / comb;
        }
    }

    cout << fixed << setprecision(15) << answer << endl;
    return 0;
}
