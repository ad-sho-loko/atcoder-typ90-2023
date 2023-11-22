#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    long long K;
    cin >> N >> K;

    for (int k = 0; k < K; k++) {
        long long N10 = 0;
        for (int i = 0; i < N.size(); i++) {
            N10 = (N10 * 8) + int(N[i] - '0');
        }

        string N9 = "";
        for (int i = 0; N10 > 0; i++) {
            N9 = char((N10 % 9 == 8 ? 5 : N10 % 9) + '0') + N9;
            N10 /= 9;
        }

        N = N9 == "" ? "0" : N9;
    }

    cout << N << endl;
    return 0;
}
