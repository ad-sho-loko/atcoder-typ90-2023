#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    long long T, X;
    cin >> Q;

    deque<int> q;
    for (int i = 0; i < Q; i++) {
        cin >> T >> X;
        if (T == 1) {
            q.push_front(X);
        } else if (T == 2) {
            q.push_back(X);
        } else {
            cout << q[X - 1] << endl;
        }
    }
}
