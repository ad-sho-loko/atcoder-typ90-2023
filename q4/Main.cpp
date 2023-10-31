#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int A[H][W];
    int srow[H], scol[W];

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cin >> A[r][c];
        }
    }

    for (int r = 0; r < H; r++) {
        int c_sum = 0;
        for (int c = 0; c < W; c++) {
            c_sum += A[r][c];
        }
        srow[r] = c_sum;
    }

    for (int c = 0; c < W; c++) {
        int r_sum = 0;
        for (int r = 0; r < H; r++) {
            r_sum += A[r][c];
        }
        scol[c] = r_sum;
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cout << srow[r] + scol[c] - A[r][c];
            if (c != W - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}