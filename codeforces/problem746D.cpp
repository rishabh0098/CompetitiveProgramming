#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;
    char cur, prev;
    int cnt = 0;
    string ans = "";
    bool flag = true;
    while (a + b > 0) {
        if (cnt < k) {
            if (a > b) {
                cur = 'G'; a--;
            } else {
                cur = 'B'; b--;
            }
        } else {
            if ((prev == 'G' && b <= 0) || (prev == 'B' && a <= 0)) {
                flag = false;
                break;
            } else {
                if (prev == 'G') {
                    cur = 'B'; b--;
                } else {
                    cur = 'G'; a--;
                }
            }
        }
        ans += cur;
        if (prev == cur) cnt++;
        else cnt = 1;
        prev = cur;
    }
    if (flag) cout << ans << endl;
    else cout << "NO" << endl;

}