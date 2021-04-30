#include <iostream>
using namespace std;
int main() {
    int t, n, k, s;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k >> s;
        int res1 = k+n;
        int res2 = 2*(k-s) + n;
        int res = min(res1,res2);
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}