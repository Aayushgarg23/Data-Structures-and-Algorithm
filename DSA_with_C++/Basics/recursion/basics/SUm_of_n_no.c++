#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void NnumbersSum(int N) {
        int sum = recursiveSum(N);
        cout << "Sum = " << sum << endl; // ✅ Output here from function
    }

private:
    int recursiveSum(int N) {
        if (N == 0) return 0;
        return N + recursiveSum(N - 1);
    }
};

int main() {
    Solution s;
    s.NnumbersSum(5);
    return 0;
}