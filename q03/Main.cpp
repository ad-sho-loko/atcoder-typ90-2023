#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int A[100001], B[100001];
vector<int> G[100001];
int dist[100001];
const int INF = (1 << 29);

void bfs(int start) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int to : G[from]) {
            if (dist[to] == INF) {
                q.push(to);
                dist[to] = dist[from] + 1;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    bfs(1);
    int maxi = -1, maxd = -1;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > maxd) {
            maxi = i;
            maxd = dist[i];
        }
    }

    bfs(maxi);
    int ansd = -1;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > ansd) {
            ansd = dist[i];
        }
    }

    cout << ansd + 1 << endl;
    return 0;
}