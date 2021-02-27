#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;

int n, ans;
int dp[101][10];

int func(int l, int x) {
	if (l == 1)
		return x == 0 ? 0 : 1;
	int& ref = dp[l][x];		// 레퍼런스
	if (ref != -1)
		return ref;

	if (x == 0)
		return ref = func(l - 1, 1) % MOD;
	if (x == 9)
		return ref = func(l - 1, 8) % MOD;
	else
		return ref = (func(l - 1, x - 1) + func(l - 1, x + 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= 9; i++)
		ans = (ans + func(n, i)) % MOD;

	cout << ans << '\n';

	return 0;
}