#include <iostream>
#include <queue>
#include <string.h>
#define MAX 50
using namespace std;
int map[MAX][MAX];
int visited[MAX][MAX];
int N, M, K;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
void bfs(int y, int x) {
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (map[ny][nx] && !visited[ny][nx]) {
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcase; cin >> testcase;
	int x, y;
	while (testcase--) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		int ans = 0;
		cin >> M >> N >> K;
		while (K--) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] && !visited[i][j]) {
					bfs(i, j);
					ans++;
				}
		cout << ans << '\n';
	}
	return 0;
}