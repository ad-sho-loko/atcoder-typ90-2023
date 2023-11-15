#include <iostream>
using namespace std;

int grundy[55][1555];

void init() {
    for (int w = 0; w <= 50; w++) {
        for (int b = 0; b <= 1500; b++) {
            // 現在の石の状態から遷移可能である集合を表す配列
            // mex[0] = 1, mex[1] = 1, mex[2...] = 0 であれば、
            // {0,1}という集合であるため、Grundy数は2になる
            int mex[1555];

            for (int k = 0; k < 1555; k++) {
                mex[k] = 0;
            }

            if (w >= 1) {
                // 選んだ山に青石をw個加え、白石を1個取り除く操作
                mex[grundy[w - 1][b + w]] = 1;
            }

            if (b >= 2) {
                // 1以上[2/b]以下の整数kを選び、選んだ山から青石をk個取り除く操作
                for (int k = 1; k <= (b / 2); k++) {
                    mex[grundy[w][b - k]] = 1;
                }
            }

            for (int k = 0; k < 1555; k++) {
                // 最小の非負整数を探す
                if (mex[k] == 0) {
                    grundy[w][b] = k;
                    break;
                }
            }
        }
    }
}

int main() {
    int N, W[100009], B[100009];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    init();

    int sum_xor = 0;
    for (int i = 0; i < N; i++) {
        sum_xor ^= grundy[W[i]][B[i]];
    }

    cout << (sum_xor == 0 ? "Second" : "First") << endl;
    return 0;
}
