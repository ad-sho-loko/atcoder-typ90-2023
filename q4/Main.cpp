#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int A[H][W];
    vector<int> srow(H);
    vector<int> scol(W);

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cin >> A[r][c];
        }
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            srow[r] += A[r][c];
            scol[c] += A[r][c];
        }
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