#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
};

Point operator-(const Point &a1, const Point &a2) {
    return Point{a1.x - a2.x, a1.y - a2.y};
}

int N;
vector<Point> X;
const double PI = 3.14159265358979;

double getAngle(Point p1, Point p2) {
    auto xd = p1.x - p2.x;
    auto yd = p1.y - p2.y;
    auto d = sqrt(xd * xd + yd * yd);

    // 1) ラジアン表記から度数表記への変換
    // π -> 180°: π / π * 180°
    // π/2 -> 90° π/2 / π * 180°
    // のように(1/π * 180)を乗ずることで計算できる

    // 2) 逆三角関数は比に応じて一意に値が定まらない。
    // eg) acos(1/√2) => 45° or 315°
    // p1から見てp2のほうがy座標が大きければ45°、小さければ315°と確定できる。
    if (p1.y <= p2.y)
        return acos(xd / d) * 180.0 / PI;
    else
        return 360.0 - acos(xd / d) * 180.0 / PI;
}

void solveSlow() {
    double maxAngle = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                // cout << "(" << i << "," << j << "," << k << ")" << endl;
                if (i == j || j == k || i == k)
                    continue;

                double I1 = getAngle(X[i], X[j]);
                double I2 = getAngle(X[i], X[k]);
                // cout << "I1:" << I1 << ", I2:" << I2 << " -> " << abs(I1 -
                // I2) << endl;

                // 2個のなす角のうち小さいほうが180°以下の角を満たす
                if (abs(I1 - I2) >= 180)
                    maxAngle = max(360.0 - abs(I1 - I2), maxAngle);
                else
                    maxAngle = max(abs(I1 - I2), maxAngle);
            }
        }
    }

    printf("%.12lf\n", maxAngle);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        X.push_back(Point{x, y});
    }

    solveSlow();
    return 0;
}