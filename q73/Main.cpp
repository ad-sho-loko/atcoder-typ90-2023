#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
vector<char> C;
vector<vector<int>> G;
long long MOD = 1000000007;

void dfs(int now, int pre) {
    long long val1 = 1, val2 = 1;
    for (auto next : G[now]) {
        if (pre == next) {
            continue;
        }

        dfs(next, now);

        if (C[now] == 'a') {
            val1 *= (dp[next][0] + dp[next][2]);
            val2 *= (dp[next][0] + dp[next][1] + 2LL * dp[next][2]);
        } else if (C[now] == 'b') {
            val1 *= (dp[next][1] + dp[next][2]);
            val2 *= (dp[next][0] + dp[next][1] + 2LL * dp[next][2]);
        }

        val1 %= MOD;
        val2 %= MOD;
    }

    if (C[now] == 'a') {
        dp[now][0] = val1;
        dp[now][2] = (val2 - val1 + MOD) % MOD;
    }

    if (C[now] == 'b') {
        dp[now][1] = val1;
        dp[now][2] = (val2 - val1 + MOD) % MOD;
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
    cout << dp[1][2] << endl;

    return 0;
}
