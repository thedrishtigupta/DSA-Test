#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string A, B;
        cin >> A >> B;

        if (A[0] != B[0] || A[N-1] != B[N-1]) {
            cout << -1 << '\n';
            continue;
        }

        set<int> good;

        for (int i = 1; i < N - 1; i++) {
            if (A[i - 1] == A[i + 1]) {
                good.insert(i);
            }
        }

        queue<int> q;

        for (int i = 1; i < N - 1; i++) {
            if (A[i] != B[i]) {
                q.push(i);
            }
        }

        int ops = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (A[i] == B[i]) continue;

            if (!good.count(i)) {
                cout << -1 << '\n';
                goto next_case;
            }

            A[i] = (A[i] == '0' ? '1' : '0');
            ops++;

            for (int j : {i - 1, i, i + 1}) {
                if (j > 0 && j < N - 1) {
                    if (A[j - 1] == A[j + 1]) {
                        good.insert(j);
                    } else {
                        good.erase(j);
                    }
                }
            }

            for (int j : {i - 1, i + 1}) {
                if (j > 0 && j < N - 1 && A[j] != B[j]) {
                    q.push(j);
                }
            }
        }

        cout << ops << '\n';

        next_case:;
    }
}