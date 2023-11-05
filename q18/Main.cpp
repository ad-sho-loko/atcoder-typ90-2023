#include <cmath>
#include <iostream>
using namespace std;
long long T, L, X, Y, Q, E;
const long double PI = 3.14159265358979;

int main() {
    cin >> T >> L >> X >> Y >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> E;
        double x = 0;
        double y = -(L / 2.0) * sin(2.0 * PI / T * E);
        double z = (L / 2.0) - (L / 2.0) * cos(2.0 * PI / T * E);
        double xy = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        double answer = atan2(z, xy) * 180.0 / PI;
        printf("%.12lf\n", answer);
    }

    return 0;
}