#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][100002];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, tem; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < n + 2; j++) {
				cin >> tem;
				dp[i][j] = tem;
			}
		}

		for (int i = 2; i < n + 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) dp[j][i] = dp[j][i] + max(dp[j + 1][i - 1], dp[j + 1][i - 2]);
				else if (j == 1) dp[j][i] = dp[j][i] + max(dp[j - 1][i - 1], dp[j - 1][i - 2]);
			}
		}

		cout << max(dp[0][n + 1], dp[1][n + 1]) << '\n';
	}
	return 0;
}