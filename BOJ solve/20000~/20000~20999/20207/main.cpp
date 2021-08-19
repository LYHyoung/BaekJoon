#include <iostream>
#include <algorithm>
using namespace std;
int cal[365];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;
		for (int j = s - 1; j < e; j++) {
			cal[j]++;
		}
	}
	int row = 0;
	int col = 0;
	int ans = 0;
	for (int i = 0; i < 365; i++) {
		if (cal[i] != 0) {
			row = max(row, cal[i]);
			col++;
		}
		else {
			ans += row * col;
			row = 0;
			col = 0;
		}
	}
	ans += row * col;
	cout << ans << '\n';
	return 0;
}