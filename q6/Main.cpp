#include <iostream>
using namespace std;

int N, K;
string S;
string ans;

int main() {
    cin >> N >> K >> S;

    for (int k = K; k >= 0; k--) {
        for (int a = 'a'; a < 'z'; a++) {
            for (int i = 0; i < N; i++) {
                if (S[i] == a && N - i > k) {
                    ans += S[i];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}