#include <iostream>
#include <vector>
using namespace std;

long long dp[100001];
vector<vector<long long>> G(100001);
vector<long long> A(100001), B(100001);

void dfs(int now, int pre) {
    dp[now] = 1;
    for (auto v : G[now]) {
        if (v != pre) {
            dfs(v, now);
            dp[now] += dp[v];
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    dfs(1, -1);

    long long answer = 0;
    for (int i = 0; i < N - 1; i++) {
        long long r = min(dp[A[i]], dp[B[i]]);
        answer += r * (N - r);
    }

    cout << answer << endl;
    return 0;
}
