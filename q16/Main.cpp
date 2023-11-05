#include <algorithm>
#include <iostream>
using namespace std;

long long N, A, B, C;

int main() {
    cin >> N >> A >> B >> C;

    long long answer = 10000;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            long long rest = N - (i * A) - (j * B);
            if (rest >= 0 && rest % C == 0) {
                answer = min(answer, i + j + (rest / C));
            }
        }
    }

    cout << answer << endl;
    return 0;
}