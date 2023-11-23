#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> par;

    UnionFind(int sz) { par.resize(sz, -1); }

    int root(int pos) {
        if (par[pos] == -1) return pos;
        par[pos] = root(par[pos]);
        return par[pos];
    }

    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        par[u] = v;
    }

    bool connected(int u, int v) {
        if (root(u) == root(v)) return true;
        return false;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q), X(Q), Y(Q), V(Q);

    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        X[i]--;
        Y[i]--;
    }

    vector<int> connected_sum(N - 1);
    for (int i = 0; i < Q; i++) {
        if (T[i] == 0) {
            connected_sum[X[i]] = V[i];
        }
    }

    vector<long long> potential(N, 0);
    for (int i = 0; i < N - 1; ++i) {
        potential[i + 1] = connected_sum[i] - potential[i];
    }

    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        if (T[i] == 0) {
            uf.unite(X[i], Y[i]);
        } else {
            if (!uf.connected(X[i], Y[i])) {
                cout << "Ambiguous" << endl;
            } else if ((X[i] + Y[i]) % 2 == 0) {
                cout << V[i] + (potential[Y[i]] - potential[X[i]]) << endl;
            } else {
                cout << potential[X[i]] + potential[Y[i]] - V[i] << endl;
            }
        }
    }

    return 0;
}
