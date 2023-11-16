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

int main() {
    long long N, K, P;
    cin >> N >> K >> P;
    vector<long long> A(N);
    vector<vector<long long>> v1(N + 1), v2(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 半分全列挙
    int mid = N / 2;
    for (int i = 0; i < (1 << mid); i++) {
        long long bit_count = 0, total_price = 0;
        for (int j = 0; j < mid; j++) {
            if (((i >> j) & 1) == 1) {
                bit_count++;
                total_price += A[j];
            }
        }
        v1[bit_count].push_back(total_price);
    }

    for (int i = 0; i < (1 << (N - mid)); i++) {
        long long bit_count = 0, total_price = 0;
        for (int j = 0; j < N - mid; j++) {
            if (((i >> j) & 1) == 1) {
                bit_count++;
                total_price += A[mid + j];
            }
        }
        v2[bit_count].push_back(total_price);
    }

    for (int i = 0; i < N; i++) {
        sort(v1[i].begin(), v1[i].end());
        sort(v2[i].begin(), v2[i].end());
    }

    long long answer = 0;
    for (int k = 0; k <= K; k++) {
        for (int i = 0; i < (int)v1[k].size(); i++) {
            int idx = lower_bound(v2[K - k].begin(), v2[K - k].end(),
                                  P - v1[k][i] + 1) -
                      v2[K - k].begin();

            answer += idx;
        }
    }

    cout << answer << endl;
    return 0;
}
