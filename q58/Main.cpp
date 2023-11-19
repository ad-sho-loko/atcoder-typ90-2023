#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    vector<int> Y(100000);
    for (int i = 0; i < 100000; i++) {
        int x = i;
        int y = 0;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        Y[i] = y;
    }

    vector<long long> visited(100000, -1);
    int n = N;
    long long k = K;
    bool looped = false;

    for (; k > 0; k--) {
        visited[n] = k;
        n = (n + Y[n]) % 100000;

        if (!looped && visited[n] != -1) {
            if (n == 0) {
                break;
            }

            long long loop_cnt = visited[n] - k + 1;
            k = k % loop_cnt;
            looped = true;
        }
    }

    cout << n << endl;
    return 0;
}
