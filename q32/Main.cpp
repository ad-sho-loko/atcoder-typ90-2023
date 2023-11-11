#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> P(N);
    int A[11][11];
    bool bad[1001][1001];

    for (int i = 0; i < N; i++) {
        P[i] = i + 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        bad[a][b] = true;
        bad[b][a] = true;
    }

    int minv = 1000001;
    do {
        bool is_impossible = false;
        for (int i = 0; i < N - 1; i++) {
            if (bad[P[i]][P[i + 1]]) {
                is_impossible = true;
            }
        }
        if (!is_impossible) {
            int v = 0;
            for (int i = 0; i < N; i++) {
                v += A[P[i]][i + 1];
            }
            minv = min(minv, v);
        }
    } while (next_permutation(P.begin(), P.end()));

    cout << (minv == 1000001 ? -1 : minv) << endl;
    return 0;
}
