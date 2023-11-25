#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> C(N);
    vector<vector<int>> G(N, vector<int>());

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);

        cout << a << b << endl;
    }

    return 0;
}