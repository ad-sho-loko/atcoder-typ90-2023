#include <iostream>
#include <vector>
using namespace std;

class segment_tree {
  private:
    long long sz;
    std::vector<long long> seg;
    std::vector<long long> lazy;
    void push(long long k) {
        if (k < sz) {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }
    void update(long long a, long long b, long long x, long long k, long long l,
                long long r) {
        push(k);
        if (r <= a || b <= l)
            return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            push(k);
            return;
        }
        update(a, b, x, k * 2, l, (l + r) >> 1);
        update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
    }
    long long range_max(long long a, long long b, long long k, long long l,
                        long long r) {
        push(k);
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return seg[k];
        long long lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        long long rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }

  public:
    segment_tree() : sz(0), seg(), lazy(){};
    segment_tree(long long N) {
        sz = 1;
        while (sz < N) {
            sz *= 2;
        }
        seg = std::vector<long long>(sz * 2, 0);
        lazy = std::vector<long long>(sz * 2, 0);
    }
    void update(long long l, long long r, long long x) {
        update(l, r, x, 1, 0, sz);
    }
    long long range_max(long long l, long long r) {
        return range_max(l, r, 1, 0, sz);
    }
};

int main() {
    int W, N, L, R;
    long long V;
    cin >> W >> N;
    long long dp[N + 1][W + 1];
    segment_tree seg[N + 1];

    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
        seg[i] = segment_tree(W + 1);
    }

    for (int i = 1; i <= N; i++) {
        cin >> L >> R >> V;

        for (int l = L; l <= R; l++) {
            dp[i][l] = max(dp[i][l], V);
        }

        // 選ばない
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
        }

        // 選ぶ
        for (int w = 0; w <= W; w++) {
            if (w - R >= 0 && w - L + 1 <= W) {
                dp[i][w] = max(seg[i - 1].range_max(w - R, w - L + 1) + V,
                               dp[i - 1][w]);
            }
        }

        for (int w = 0; w <= W; w++) {
            printf("(%d,%d) => %lld\n", i, w, dp[i][w]);
            seg[i].update(w, w + 1, dp[i][w]);
        }
    }

    long long maxv = -1;
    for (int i = 1; i <= N; i++) {
        if (dp[i][W] > 0) {
            maxv = max(maxv, dp[i][W]);
        }
    }

    cout << maxv << endl;
    return 0;
}