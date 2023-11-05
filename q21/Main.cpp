#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B;
vector<vector<int>> G(100001);
vector<vector<int>> H(100001);
bool used[100001];
vector<int> I;
long long cnt = 0;

void dfs(int now) {
    used[now] = true;
    for (auto v : G[now]) {
        if (!used[v]) {
            dfs(v);
        }
    }
    I.push_back(now);
}

void dfs2(int now) {
    used[now] = true;
    cnt++;
    for (auto v : H[now]) {
        if (!used[v]) {
            dfs2(v);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        G[A - 1].push_back(B - 1);
        H[B - 1].push_back(A - 1);
    }

    // 1st DFS: 帰りがけ順に深さ優先探索する
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    // 2nd DFS
    for (int i = 0; i < N; i++) {
        used[i] = false;
    }

    long long answer = 0;
    reverse(I.begin(), I.end());
    for (int i : I) {
        cnt = 0;
        if (!used[i]) {
            dfs2(i);
            answer += ((cnt - 1) * cnt) / 2;
        }
    }

    cout << answer << endl;
    return 0;
}
