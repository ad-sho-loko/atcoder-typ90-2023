#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G(100000);
int color[100000];

void dfs(int n, int c) {
    color[n] = c;
    for (auto n : G[n]) {
        if (color[n] == -1) {
            dfs(n, 1 - c);
        }
    }
}

int main() {
    int N, A, B;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        G[A - 1].push_back(B - 1);
        G[B - 1].push_back(A - 1);
    }

    for (int i = 0; i < N; i++) {
        color[i] = -1;
    }

    dfs(0, 0);

    int nr = 0, nw = 0;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            nr += 1;
        } else {
            nw += 1;
        }
    }

    vector<int> answers;
    for (int i = 0; i < N; i++) {
        if (nr > nw) {
            if (color[i] == 0) {
                answers.push_back(i + 1);
            }
        } else {
            if (color[i] == 1) {
                answers.push_back(i + 1);
            }
        }
    }

    for (int i = 0; i < N / 2; i++) {
        if (i == N / 2 - 1) {
            cout << answers[i] << endl;
        } else {
            cout << answers[i] << " ";
        }
    }

    return 0;
}