#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector<int> C1(N + 1), C2(N + 1);
    vector<long long> T1(N + 1);
    vector<long long> T2(N + 1);

    for (int i = 1; i <= N; i++) {
        int C, P;
        cin >> C >> P;
        if (C == 1) {
            C1[i] = P;
        } else {
            C2[i] = P;
        }
    }

    for (int i = 1; i <= N; i++) {
        T1[i] = T1[i - 1] + C1[i];
        T2[i] = T2[i - 1] + C2[i];
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << T1[R] - T1[L - 1] << " " << T2[R] - T2[L - 1] << endl;
    }

    return 0;
}