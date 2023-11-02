#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    bool r = a < powl(c, b);
    cout << (r ? "Yes" : "No") << endl;
    return 0;
}