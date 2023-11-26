#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N);

    long long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
    }

    long double target = total / 10.0;

    int l = 0, r = 0;
    bool is_left_over = false, is_right_over = false;
    long double now = A[0];

    while (!is_left_over || !is_right_over) {
        if (now == target) {
            cout << "Yes" << endl;
            return 0;
        }

        if (now > target) {
            now -= A[l];
            l++;
            if (l >= N) {
                l %= N;
                is_left_over = true;
            }
        } else {
            r++;
            if (r >= N) {
                r %= N;
                is_right_over = true;
            }
            now += A[r];
        }
    }

    cout << "No" << endl;
    return 0;
}