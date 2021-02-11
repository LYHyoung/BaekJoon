#include <iostream>		// 9205
#include <vector>
#include <algorithm>
#define MAX 1000
#define INF 987654321
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Testcase; cin >> Testcase;
	while (Testcase--) {
		int n; cin >> n;
		vector<pair<int, int>> pos(n + 2);
		vector<vector<ll>> D(n + 2, vector<ll>(n + 2, 0));
		for (int i = 0; i < n + 2; i++) {
			int x, y; cin >> x >> y;
			pos[i] = { x,y };
			//D[i][i] = 1;			// ?	// 없애도 '맞았습니다!!'
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				int dist_x = abs(pos[i].first - pos[j].first);
				int dist_y = abs(pos[i].second - pos[j].second);
				int dist = dist_x + dist_y;
				if (dist <= MAX)
					D[i][j] = D[j][i] = 1;		// ?
			}
		}
		for (int k = 0; k < n + 2; k++)
			for (int i = 0; i < n + 2; i++)
				for (int j = 0; j < n + 2; j++)
					if (D[i][k] && D[k][j])
						D[i][j] = 1;
		cout << (D[0][n + 1] ? "happy\n" : "sad\n");
	}
	return 0;
}
