#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
int map[MAX][MAX][MAX];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dh[] = { 0,0,0,0,1,-1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M, N, H;
	cin >> M >> N >> H;

	queue<pair<int, pair<int, int>>> q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 1) q.push(make_pair(k, make_pair(i, j)));
			}
		}
	}

	while (!q.empty()) {
		auto node = q.front();
		q.pop();

		int x = node.second.second;
		int y = node.second.first;
		int h = node.first;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = h + dh[i];

			if (nx >= 0 && ny >= 0 && nh >= 0 && nx < M && ny < N && nh < H) {
				if (map[nh][ny][nx] == 0) {
					q.push(make_pair(nh, make_pair(ny, nx)));
					map[nh][ny][nx] = map[h][y][x] + 1;
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[k][i][j] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				ans = max(ans, map[k][i][j]);
			}
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}