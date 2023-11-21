#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N + 1), B(N + 1);
    vector<vector<int>> G(N + 1, vector<int>(0));

    queue<int> q;
    vector<bool> visited(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(i);
        G[B[i]].push_back(i);
        if (i == A[i] || i == B[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    vector<int> path;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        path.push_back(now);

        for (auto next : G[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    reverse(path.begin(), path.end());
    if (path.size() == N) {
        for (int i = 0; i < N; i++) {
            cout << path[i] << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
