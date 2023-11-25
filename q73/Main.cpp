#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
vector<char> C;
vector<vector<int>> G;

void dfs(int now, int pre) {
    for (auto next : G[now]) {
        if (pre == next) {
            continue;
        }

        dfs(next, now);

        if (C[now] == 'a') {
            dp[now][0] *= dp[next][0] + dp[next][2];
        } else {
            dp[now][1] *= dp[next][1] + dp[next][2];
        }
    }

    if (C[now] == 'a') {
        dp[now][0] = 1;
        dp[now][2] = 0;
        // dp[pos][2] = (val2 - val1 + mod) % mod;
    }

    if (C[now] == 'b') {
        dp[now][1] = 1;
        dp[now][2] = 0;
        // dp[pos][2] = (val2 - val1 + mod) % mod;
    }
}

int main() {
    int N;
    cin >> N;

    C.resize(N + 1);
    G.resize(N + 1, vector<int>());
    dp.resize(N + 1, vector<long long>(3));

    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, -1);
    return 0;
}
