#include <bits/stdc++.h>
using namespace std;

// vector
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

void tooSlow() {
    long long N, K, P;
    cin >> N >> K >> P;
    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<vector<long long>>> dp(
        N, vector<vector<long long>>(K + 1, vector<long long>(0)));

    for (int i = 0; i < N; i++) {
        dp[i][1].push_back(A[i]);
    }

    for (int k = 2; k <= K; k++) {
        for (int i = k - 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                for (auto p : dp[j][k - 1]) {
                    if (p + A[i] <= P) {
                        dp[i][k].push_back(p + A[i]);
                    }
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 0; i < N; i++) {
        answer += dp[i][K].size();
    }

    cout << answer << endl;
}

int main() {
    long long N, K, P;
    cin >> N >> K >> P;
    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    return 0;
}
