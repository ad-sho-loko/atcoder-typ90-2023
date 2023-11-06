#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    set<string> st;

    for (int i = 0; i < N; i++) {
        cin >> S;
        if (st.end() != st.find(S)) {
            continue;
        }

        st.insert(S);
        cout << i + 1 << endl;
    }
    return 0;
}
