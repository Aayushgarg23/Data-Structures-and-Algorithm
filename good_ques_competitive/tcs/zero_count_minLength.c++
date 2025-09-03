#include <iostream>
using namespace std;

int main() {
    int l, k;
    cin >> l >> k;

    if (l == k) {
        cout << l - k;
        return 0;
    }

    l -= k;
    int ans = (l / (k + 1));
    cout << ans + (l % (k + 1) > 0 ? 1 : 0);
    return 0;
}