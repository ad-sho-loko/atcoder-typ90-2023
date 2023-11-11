#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N, Q;
    long long X, Y;
    long long minX = 1LL << 18, minY = 1LL << 18;
    long long maxX = -(1LL << 18), maxY = -(1LL << 18);
    long long Px[100001], Py[100001];
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        long long rX = X + Y;
        long long rY = Y - X;
        Px[i] = rX;
        Py[i] = rY;
        minX = min(minX, rX);
        maxX = max(maxX, rX);
        minY = min(minY, rY);
        maxY = max(maxY, rY);
    }

    long long q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        long long c1 = abs(Px[q] - maxX);
        long long c2 = abs(Px[q] - minX);
        long long c3 = abs(Py[q] - maxY);
        long long c4 = abs(Py[q] - minY);
        cout << max({c1, c2, c3, c4}) << endl;
    }

    return 0;
}
