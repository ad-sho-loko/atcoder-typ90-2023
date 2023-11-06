#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    long long A[1000], B[1000];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long diff = 0;
    for (int i = 0; i < N; i++) {
        diff += abs(A[i] - B[i]);
    }

    if (diff > K) {
        cout << "No" << endl;
        return 0;
    }

    cout << (abs(diff - K) % 2 == 0 ? "Yes" : "No") << endl;
    return 0;
}