#include <iostream>			// 10159
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < M; i++) {
		int big, small; cin >> big >> small;
		v[big - 1][small - 1] = 1;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][k] && v[k][j]) v[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++)
			if (!v[i][j] && !v[j][i]) cnt++;
		cout << cnt - 1 << '\n';
	}
	return 0;
}