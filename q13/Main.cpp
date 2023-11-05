#include <functional> // std::greater
#include <iostream>
#include <queue> // std::priority_queue
#include <vector>
using namespace std;

using Pair = pair<long long, int>;

int N, M;
long long A[100001], B[100001], C[100001];
long long dist[100001], dist1[100001], distN[100001];
long long MAX = 1L << 60;

vector<vector<Pair>> G;

void dijkstra(int start) {
    // Init
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.push({0, start});

    for (int i = 0; i < N; i++) {
        dist[i] = MAX;
    }
    dist[start] = 0;

    // Do
    while (!q.empty()) {
        Pair p = q.top();
        q.pop();
        int fromIndex = p.second;
        int fromDistance = p.first;
        for (auto to : G[fromIndex]) {
            auto toIndex = to.second;
            auto toDistance = to.first;
            auto distance = fromDistance + toDistance;
            if (distance < dist[toIndex]) {
                dist[toIndex] = distance;
                q.push({distance, toIndex});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        G[A[i] - 1].push_back({C[i], B[i] - 1});
        G[B[i] - 1].push_back({C[i], A[i] - 1});
    }

    dijkstra(0);
    for (int i = 0; i < N; i++) {
        dist1[i] = dist[i];
    }

    dijkstra(N - 1);
    for (int i = 0; i < N; i++) {
        distN[i] = dist[i];
    }

    for (int i = 0; i < N; i++) {
        cout << dist1[i] + distN[i] << endl;
    }

    return 0;
}
