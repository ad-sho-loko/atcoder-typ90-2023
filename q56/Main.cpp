#include <bits/stdc++.h>
using namespace std;

int LMT = 100000;

// vector
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); i++) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

string dfs(vector<int> &A, vector<int> &B, vector<vector<bool>> &dp, int i, int p, string s) {
    if (i == 0) {
        if (p == A[i]) {
            return "A" + s;
        }

        return "B" + s;
    }

    if (p - A[i] >= 0 && dp[i - 1][p - A[i]]) {
        return dfs(A, B, dp, i - 1, p - A[i], "A" + s);
    }

    if (p - B[i] >= 0 && dp[i - 1][p - B[i]]) {
        return dfs(A, B, dp, i - 1, p - B[i], "B" + s);
    }

    return "Impossible";
}

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<bool>> dp(N, vector<bool>(LMT + 1));

    dp[0][A[0]] = true;
    dp[0][B[0]] = true;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= LMT; j++) {
            if (dp[i - 1][j]) {
                if (j + A[i] <= LMT) {
                    dp[i][j + A[i]] = true;
                }
                if (j + B[i] <= LMT) {
                    dp[i][j + B[i]] = true;
                }
            }
        }
    }

    string answer = dfs(A, B, dp, N - 1, S, "");
    cout << answer << endl;

    return 0;
}
