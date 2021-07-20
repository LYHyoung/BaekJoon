#include <iostream>

using namespace std;
int dp[41];
int fibonacci(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	if (dp[n] != 0)
		return dp[n];
	else
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
	int T; cin >> T;
	dp[0] = 0; dp[1] = 1;
	fibonacci(40);
	while (T--) {
		int x; cin >> x;
		if (x == 0)
			printf("1 0\n");
		else if (x == 1)
			printf("0 1\n");
		else
			printf("%d %d\n", dp[x - 1], dp[x]);
	}
	
	return 0;
}