#include <iostream>		// 12782
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string N;
		string M;
		cin >> N >> M;
		int diff = 0;
		int count_N = 0, count_M = 0;
		for (int i = 0; i < N.size(); i++) {
			if (N[i] != M[i]) diff++;
			if (N[i] == '1') count_N++;
			if (M[i] == '1') count_M++;
		}
		cout << abs(count_N - count_M) + (diff - abs(count_N - count_M)) / 2 << '\n';
	}
	return 0;
}