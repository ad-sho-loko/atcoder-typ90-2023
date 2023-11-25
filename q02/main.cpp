#include <iostream>
using namespace std;

int N;

bool isValid(string str) {
    int score = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == '(')
            score++;
        else
            score--;

        if (score < 0)
            return false;
    }

    return score == 0;
}

int main() {
    cin >> N;

    for (int i = 0; i < (1 << N); i++) {
        string cand = "";
        for (int j = N - 1; j >= 0; j--) {
            if ((i & (1 << j)) == 0) {
                cand += "(";
            } else {
                cand += ")";
            }
        }

        if (isValid(cand))
            cout << cand << endl;
    }

    return 0;
}