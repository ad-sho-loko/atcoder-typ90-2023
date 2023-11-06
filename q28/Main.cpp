#include <iostream>
using namespace std;

int G[1001][1001];

int main() {
    int N, lx, ly, rx, ry;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> lx >> ly >> rx >> ry;
        G[lx][ly] += 1;
        G[rx][ly] -= 1;
        G[lx][ry] -= 1;
        G[rx][ry] += 1;
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            G[i][j] += G[i][j - 1];
        }
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            G[i][j] += G[i - 1][j];
        }
    }

    int answer[1 << 18];
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (G[i][j] >= 1) {
                answer[G[i][j]] += 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << endl;
    }

    return 0;
}