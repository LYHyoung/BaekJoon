#include <iostream>
#include <cstring>
#define MAX 31
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int T; cin >> T;
	int dp[MAX][MAX];
	while (T--) {
		memset(dp, 0, sizeof(dp));
		int N, M; cin >> N >> M;
		for (int i = 1; i <= M; i++)
			dp[1][i] = i;
		for (int i = 2; i <= N; i++)
			for (int j = i; j <= M; j++)
				for (int k = j; k >= i; k--)
					dp[i][j] = dp[i][j] + dp[i - 1][k - 1];
		cout << dp[N][M] << '\n';
	}
	return 0;
}