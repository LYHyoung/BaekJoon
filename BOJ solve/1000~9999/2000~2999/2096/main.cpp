#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int n;
int map[MAX][3];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	int max_dp[3] = { 0,0,0 }, min_dp[3] = { 0,0,0 };
	for (int i = 0; i < n; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];

		// 최대
		int temp0 = max_dp[0]; int temp2 = max_dp[2];
		max_dp[0] = max(max_dp[0], max_dp[1]) + map[i][0];
		max_dp[2] = max(max_dp[1], max_dp[2]) + map[i][2];
		max_dp[1] = max(max(temp0, max_dp[1]), temp2) + map[i][1];

		// 최소
		temp0 = min_dp[0], temp2 = min_dp[2];
		min_dp[0] = min(min_dp[0], min_dp[1]) + map[i][0];
		min_dp[2] = min(min_dp[1], min_dp[2]) + map[i][2];
		min_dp[1] = min(min(temp0, min_dp[1]), temp2) + map[i][1];
	}

	int ans1 = max(max(max_dp[0], max_dp[1]), max_dp[2]);
	int ans2 = min(min(min_dp[0], min_dp[1]), min_dp[2]);

	cout << ans1 << ' ' << ans2;

	return 0;
}