
#include <iostream>		// 9009
#include <vector>
using namespace std;
// https://blog.naver.com/kts1801/220974939723
int main() {
	int T;
	int d[30] = { 1,1 };
	for (int i = 2; i < 30; i++) d[i] = d[i - 1] + d[i - 2];
	cin >> T;

	while (T--) {
		int n, t = 0;
		cin >> n;
		vector<int> ans;
		for (int i = 29; i >= 0; i--) {
			if (d[i] <= n) {
				n -= d[i];
				ans.push_back(d[i]);
				t++;
			}
		}

		for (int i = ans.size()-1; i >= 0; i--)
			cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}
