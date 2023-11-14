#include <iostream>
#include <vector>
using namespace std;

long long N, Q, T, X, Y;

int main() {
    cin >> N >> Q;
    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long shift = 0;
    for (int i = 0; i < Q; i++) {
        cin >> T;
        cin >> X >> Y;
        long long Ax = (X - 1 - shift);
        long long Ay = (Y - 1 - shift);
        Ax = Ax < 0 ? Ax + N : Ax;
        Ay = Ay < 0 ? Ay + N : Ay;
        if (T == 1) {
            long long tmp = A[Ax];
            A[Ax] = A[Ay];
            A[Ay] = tmp;
        } else if (T == 2) {
            shift = (shift + 1) % N;
        } else {
            cout << A[Ax] << endl;
        }
    }

    return 0;
}