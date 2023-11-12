#include <iostream>
#include <vector>
using namespace std;

int dp[100001];
vector<vector<int>> G(100001);

void dfs(int pos) {
    for (auto v : G[pos]) {
    }
}

int main() {
    int N, A, B;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    dfs(1);
    return 0;
}
