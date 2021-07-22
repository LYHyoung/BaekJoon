#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int x_s, y_s, x_e, y_e; cin >> x_s >> y_s >> x_e >> y_e;
		int n; cin >> n;
		int count = 0;
		while (n--) {
			int x, y, r; cin >> x >> y >> r;
			int d1, d2;
			d1 = (x_s - x) * (x_s - x) + (y_s - y) * (y_s - y);
			bool chk1 = d1 > r* r ? false : true;
			d2 = (x_e - x) * (x_e - x) + (y_e - y) * (y_e - y);
			bool chk2 = d2 > r * r ? false : true;
			if (chk1 ^ chk2) count++;
		}
		cout << count << '\n';
	}
	return 0;
}