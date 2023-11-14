#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
long long N, K;

int main() {
    cin >> N >> K;
    vector<long long> A(N), B(N), V;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        V.push_back(A[i] - B[i]);
        V.push_back(B[i]);
    }

    sort(V.rbegin(), V.rend());

    long long answer = 0;
    for (int i = 0; i < K; i++) {
        answer += V[i];
    }

    cout << answer << endl;
    return 0;
}
