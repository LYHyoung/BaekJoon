#include <iostream>
#include <algorithm>
#define INF 1e9

typedef long long ll;
using namespace std;

// 1 2 3 4 5 6 7 8 9 0
// 2 5 5 4 5 6 3 7 6 6
ll num[9] = { 0,0,1,7,4,2,0,8,10 };
ll dp[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 9; i++) {
		dp[i] = num[i];
	}
	dp[6] = 6;
	for (int i = 9; i <= 100; i++) {
		dp[i] = dp[i - 2] * 10 + num[2];

		for (int j = 3; j <= 7; j++)
			dp[i] = min(dp[i - j] * 10 + num[j], dp[i]);
	}
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		cout << dp[n] << ' ';
		while (n) {
			if (n % 2 != 0) {
				cout << 7;
				n -= 3;
			}
			else {
				cout << 1;
				n -= 2;
			}
		}
		cout << '\n';
	}
	return 0;
}
