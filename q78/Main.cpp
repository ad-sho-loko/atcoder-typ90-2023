#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int answer = 0;
    for (int i = 2; i <= N; i++) {
        int cnt = 0;
        for (int j = 0; j < G[i].size(); j++) {
            if (i > G[i][j]) {
                cnt++;
            }
        }
        if (cnt == 1) {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}