#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int A[N];
    map<int, int> m;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int l = 0, r = 0, kind = 0, curlen = 0, maxl = 0;

    while (l < N && r < N) {
        if (m.count(A[r]) != 0) {
            m[A[r]] = r;
            r++;
            curlen++;
            maxl = max(maxl, curlen);
        } else if (K - kind > 0) {
            m[A[r]] = r;
            r++;
            curlen++;
            maxl = max(maxl, curlen);
            kind++;
        } else {
            if (l == m[A[l]]) {
                kind--;
                m.erase(A[l]);
            }
            l++;
            curlen--;
        }
    }

    cout << maxl << endl;
    return 0;
}