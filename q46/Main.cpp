#include <iostream>
#include <vector>
using namespace std;

long long N, x;

int main() {
    cin >> N;
    vector<long long> A(46), B(46), C(46);

    for (int i = 0; i < N; i++) {
        cin >> x;
        A[x % 46]++;
    }

    for (int i = 0; i < N; i++) {
        cin >> x;
        B[x % 46]++;
    }

    for (int i = 0; i < N; i++) {
        cin >> x;
        C[x % 46]++;
    }

    long long ans = 0;
    for (int i = 0; i < 46; i++) {
        for (int j = 0; j < 46; j++) {
            for (int k = 0; k < 46; k++) {
                if ((i + j + k) % 46 == 0) {
                    ans += A[i] * B[j] * C[k];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
