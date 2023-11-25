#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    long long g = gcd(A, gcd(B, C));
    cout << (A / g - 1) + (B / g - 1) + (C / g - 1) << endl;

    return 0;
}