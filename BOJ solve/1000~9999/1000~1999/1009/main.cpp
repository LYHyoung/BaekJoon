#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int res, a, b; cin >> a >> b;
		res = a;
		for (int i = 0; i < b - 1; i++)
			res = res * a % 10;

		int ans = res % 10;
		
		if (ans == 0)
			cout << 10 << '\n';
		else
			cout << ans << '\n';
	}
	return 0;
}