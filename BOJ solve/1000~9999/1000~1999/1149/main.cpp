#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N, ans;
int MAP[MAX][3];
int DP[MAX][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> MAP[i][j];
		}
	}
	DP[0][0] = DP[0][1] = DP[0][2] = 0;
	MAP[0][0] = MAP[0][1] = MAP[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + MAP[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + MAP[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + MAP[i][2];
	}
	ans = min(min(DP[N][0], DP[N][1]), DP[N][2]);
	cout << ans << '\n';

	return 0;
}