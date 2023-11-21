#include <bits/stdc++.h>
using namespace std;

const int INF = 300009;

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

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> LIS(N, INF), P, Q;

    // Left LIS
    for (auto a : A) {
        auto cnt = lower_bound(LIS.begin(), LIS.end(), a) - LIS.begin();
        LIS[cnt] = a;
        P.push_back(cnt + 1);
    }

    // Right LIS
    LIS = vector<int>(N, INF);
    reverse(A.begin(), A.end());
    for (auto a : A) {
        auto cnt = lower_bound(LIS.begin(), LIS.end(), a) - LIS.begin();
        LIS[cnt] = a;
        Q.push_back(cnt + 1);
    }

    int answer = -1;
    for (int i = 0; i < N; i++) {
        answer = max(answer, P[i] + Q[N - i - 1] - 1);
    }

    cout << answer << endl;
    return 0;
}
