#include <iostream>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;
int L, W, ans;
char map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Bigger(int a, int b) { if (a > b) return a; return b; }
int bfs(int a, int b) {
	int t = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (t < visited[x][y]) t = visited[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > L || ny > W) continue;
			if (visited[nx][ny] == 0 && map[nx][ny] == 'L') {
				q.push({ nx,ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	return t;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
	cin >> L >> W;
	for (int i = 1; i <= L; i++)
		for (int j = 1; j <= W; j++)
			cin >> map[i][j];
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == 'L') {		// find the land
				int t = bfs(i, j);
				ans = Bigger(ans, t);
				memset(visited, 0, sizeof(visited));		// resetting job
			}
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}