#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
  private:
    vector<int> par;

    int root(int n) {
        if (par[n] == -1)
            return n;

        return root(par[n]);
    }

  public:
    UnionFind(int size) { par.resize(size, -1); }

    bool same(int a, int b) { return root(a) == root(b); }

    void unite(int a, int b) {
        auto ra = root(a);
        auto rb = root(b);
        par[rb] = ra;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    auto uf = new UnionFind(H * W);
    bool used[H][W];

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            int r, c;
            cin >> r >> c;
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};

            auto me = (r - 1) * W + (c - 1);
            used[r - 1][c - 1] = true;

            for (int i = 0; i < 4; i++) {
                auto rx = (r - 1) + dx[i];
                auto ry = (c - 1) + dy[i];
                if (rx < 0 || rx >= W || ry < 0 || ry >= H) {
                    continue;
                }

                if (used[rx][ry]) {
                    auto other = rx * W + ry;
                    uf->unite(me, other);
                }
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if (!used[ra - 1][ca - 1] || !used[rb - 1][cb - 1]) {
                cout << "No" << endl;
                continue;
            }

            auto a = (ra - 1) * W + (ca - 1);
            auto b = (rb - 1) * W + (cb - 1);
            cout << (uf->same(a, b) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}