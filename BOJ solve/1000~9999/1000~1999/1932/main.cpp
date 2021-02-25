#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501
using namespace std;

int dp[MAX][MAX];
int arr[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;  cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << '\n';

	return 0;
}