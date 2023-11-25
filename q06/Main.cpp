#include <iostream>
#include <vector>
using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> K >> S;

    // i行目以降でjのアルファベットが登場する初めての添え字を格納する
    // 登場しない場合はありえない添え字（文字列そのものの長さを格納する）
    // eg) abca (N=4)
    //        a b c d e f g...
    // [0(a)] 0 1 2 4
    // [1(b)] 3 1 2 4
    // [2(c)] 3 4 2 4
    // [3(a)] 3 4 4 4

    int nex[N + 1][26];
    for (int i = 0; i < 26; i++) {
        nex[N][i] = N;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((S[i] - 'a') == j) {
                nex[i][j] = i;
            } else {
                nex[i][j] = nex[i + 1][j];
            }
        }
    }

    // 答えのk文字目にはi文字目以降のj番目のアルファベットを採用できるかチェックする
    int k = 0;
    string answer = "";
    for (int i = 0; k < K;) {
        for (int j = 0; j < 26; j++) {
            // 採用する文字列の最小の添え字（N-nex[i][j]）が残りに必要な文字列の長さ（K-k）を満たすかどうか
            if (nex[i][j] != -1 && N - nex[i][j] >= K - k) {
                answer += 'a' + j;
                i = nex[i][j] + 1;
                k++;
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}