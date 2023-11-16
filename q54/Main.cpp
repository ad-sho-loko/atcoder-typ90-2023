#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M, K, R;
    cin >> N >> M;
    vector<vector<int>> G(N + M);

    for (int i = 0; i < M; i++) {
        cin >> K;
        for (int k = 0; k < K; k++) {
            cin >> R;
            R--;
            G[R].push_back(N + i);
            G[N + i].push_back(R);
        }
    }

    queue<int> q;
    vector<int> dist(N + M, -2);
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        auto from = q.front();
        q.pop();

        for (auto to : G[from]) {
            if (dist[to] == -2) {
                dist[to] = dist[from] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dist[i] / 2 << endl;
    }

    return 0;
}