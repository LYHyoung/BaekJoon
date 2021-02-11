#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	visited[1][1][1] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();
		if (y == N && x == M) {
			cout << visited[y][x][block] << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 1 && ny >= 1 && nx <= M && ny <= N) {
				// 벽 O, 아직 부수지 않은 경우
				if (map[ny][nx] && block) {
					visited[ny][nx][block - 1] = visited[y][x][block] + 1;
					q.push(make_pair(make_pair(ny, nx), block - 1));
				}
				// 벽 X, 방문한적 없는 경우
				if (!map[ny][nx] && !visited[ny][nx][block]) {
					visited[ny][nx][block] = visited[y][x][block] + 1;
					q.push(make_pair(make_pair(ny, nx), block));
				}
			}
		}
	}
	cout << -1 << '\n';
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string line; cin >> line;
		for (int j = 1; j <= M; j++)
			map[i][j] = (int)line[j - 1] - 48;
	}
	bfs();
	return 0;
}