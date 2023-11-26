#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    long long answer = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'b') {
            answer += (1LL << i);
        }
        if (S[i] == 'c') {
            answer += (1LL << (i + 1));
        }
    }

    cout << answer << endl;
    return 0;
}
