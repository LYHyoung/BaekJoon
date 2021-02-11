#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;
queue<pair<int, int>> q;
int map[MAX][MAX];
int visited[MAX][MAX];
int N, M, ans;			// M : 가로 , N : 세로
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!map[nx][ny]) {
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++)		// 세팅
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)		// queue에 push 해준다
				q.push({ i,j });
		}
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
			if (ans < map[i][j])
				ans = map[i][j];
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}