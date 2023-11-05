#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100001], B[100001], C[100001];
vector<vector<int>> G;

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    return 0;
}