#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
#define INF 1e9
using namespace std;
int map[MAX][MAX];
int N, M;
int cnt[MAX][MAX];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
void bfs() {
	cnt[1][1] = 1;
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (cnt[nx][ny] > cnt[x][y] + 1 && map[nx][ny]) {
				cnt[nx][ny] = cnt[x][y] + 1;;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string line; cin >> line;
		for (int j = 1; j <= M; j++) {
			int tmp = line[j - 1] - 48;			// 48을 빼주어야 한다
			map[i][j] = tmp;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cnt[i][j] = INF;
		}
	}
	bfs();
	cout << cnt[N][M];
	return 0;
}