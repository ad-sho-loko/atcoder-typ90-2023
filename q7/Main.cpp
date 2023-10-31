#include <algorithm>
#include <iostream>
using namespace std;

int N, Q;
int A[300001];
int B[300001];
const int INF = 2000000000;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    cin >> Q;

    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A + N);

    for (int i = 0; i < N; i++) {
        int posR = lower_bound(A, A + N, B[i]) - A;
        int diffL = INF, diffR = INF;
        if (posR <= N - 1)
            diffR = abs(B[i] - A[posR]);
        if (posR >= 1)
            diffL = abs(B[i] - A[posR - 1]);

        cout << min(diffL, diffR) << endl;
    }

    return 0;
}