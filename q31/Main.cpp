#include <iostream>
using namespace std;

int main() {
    int N, W[100009], B[100009];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    bool answer = false;
    for (int i = 0; i < N; i++) {
        answer ^= ((B[i] + W[i] * 2) % 2 == 0);
    }

    cout << (answer ? "First" : "Second") << endl;
    return 0;
}
