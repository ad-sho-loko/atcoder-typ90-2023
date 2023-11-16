#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    int N, A;
    cin >> N;

    long long answer = 1;

    for (int i = 0; i < N; i++) {
        auto total = 0ll;
        for (int j = 0; j < 6; j++) {
            cin >> A;
            total = (total + A) % MOD;
        }
        answer = (answer % MOD * total) % MOD;
    }

    cout << answer << endl;
    return 0;
}