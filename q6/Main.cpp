#include <iostream>
#include <vector>
using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> K >> S;

    // i行目以降でjのアルファベットが登場する初めての添え字を格納する
    // eg) abca
    //     a b c d...
    // [0] 0 1 2 -1
    // [1] 3 1 2 -1
    // [2] 3 -1 2 -1
    // [3] 3 -1 -1 -1

    int nex[N][26];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            nex[i][j] = -1;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            nex[j][S[i] - 'a'] = i;
        }
    }

    // 答えのk文字目にはi文字目以降のj番目のアルファベットを採用できるかチェックする
    int i = 0;
    string answer = "";
    for (int k = 0; k < K; k++) {
        for (int j = 0; j < 26; j++) {
            // 採用する文字列の最小の添え字（N-nex[i][j]）が残りに必要な文字列の長さ（K-k）を満たすかどうか
            if (nex[i][j] != -1 && N - nex[i][j] >= K - k) {
                answer += S[j];
                i = nex[i][j] + 1;
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}