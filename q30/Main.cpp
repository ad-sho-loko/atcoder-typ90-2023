#include <iostream>
using namespace std;

int cnt[10000009];

int main() {
    int N, K;
    cin >> N >> K;

    // O(N)
    for (int i = 2; i <= N; i++) {
        if (cnt[i] >= 1)
            continue;
        // O(loglogN)
        for (int j = i; j <= N; j += i) {
            cnt[j] += 1;
        }
    }
    // => O(NloglogN)

    int answer = 0;
    for (int i = 2; i <= N; i++) {
        if (cnt[i] >= K) {
            answer += 1;
        }
    }

    cout << answer << endl;
    return 0;
}