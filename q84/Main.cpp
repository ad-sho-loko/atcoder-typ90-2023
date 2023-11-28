#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    string S;

    cin >> N >> S;

    vector<long long> O(N + 1), X(N + 1);
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'o') {
            O[i] = i;
            X[i] = X[i - 1];
        }
        if (S[i - 1] == 'x') {
            O[i] = O[i - 1];
            X[i] = i;
        }
    }

    long long Answer = 0;
    for (int i = 1; i <= N; i++) {
        Answer += 1LL * min(O[i], X[i]);
    }

    cout << Answer << endl;
    return 0;
}