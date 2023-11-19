#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M;

    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> T;
        int a;
        for (int j = 0; j < T; j++) {
            cin >> a;
            A[i].push_back(a);
        }
    }

    vector<int> S(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
    }

        return 0;
}