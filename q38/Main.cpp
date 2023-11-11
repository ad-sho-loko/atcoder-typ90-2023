#include <cmath>
#include <iostream>
using namespace std;

unsigned long long A, B;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    long long A, B, THRESHOLD = 1000000000000000000LL;
    cin >> A >> B;

    long long C = A / gcd(A, B);
    if (B <= THRESHOLD / C)
        cout << C * B << endl;
    else
        cout << "Large" << endl;

    return 0;
}
