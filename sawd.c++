#include <bits/stdc++.h>
using namespace std;

int getMinimumMoves(vector<int>& tasks) {
    int moves = 0;
    for (int i = 0; i < (int)tasks.size() - 1; ++i) {
        if (tasks[i] < tasks[i + 1]) {
            int diff = tasks[i + 1] - tasks[i];
            tasks[i + 1] -= diff;
            moves += diff;
        }
    }
    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i];
    }

    cout << getMinimumMoves(tasks) << endl;
    return 0;
}
