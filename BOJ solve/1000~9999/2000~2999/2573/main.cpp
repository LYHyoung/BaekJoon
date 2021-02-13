#include <iostream>
#include <queue>
#include <cstring>
#define MAX 301
using namespace std;
int N, M;
int map[MAX][MAX];
int n[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= M) {
				if (visited[nx][ny] == 0 && map[nx][ny] != 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int melt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] == 0) cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	int time = 0;
	while (1) {
		int island = 0;
		memset(visited, false, sizeof(visited));
		memset(n, 0, sizeof(n));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] != 0 && visited[i][j] == 0) {
					island++;
					bfs(i, j);
				}
			}
		}
		if (island >= 2) {
			cout << time << '\n';
			break;
		}
		if (island == 0) {
			cout << 0 << '\n';
			break;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] != 0) {
					n[i][j] = map[i][j] - melt(i, j);
					if (n[i][j] < 0) n[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				map[i][j] = n[i][j];
			}
		}
		time++;
	}
	return 0;
}