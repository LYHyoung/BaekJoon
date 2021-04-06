#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 8
using namespace std;
int map[MAX][MAX];
int tmp[MAX][MAX];
int N, M, result;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
void bfs() {
	int spread[MAX][MAX];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			spread[i][j] = tmp[i][j];
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (spread[i][j] == 2)
				q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (spread[nx][ny] == 0) {
					spread[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}
	int empty = 0;	// count blank(0)
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (spread[i][j] == 0)
				empty += 1;
	result = max(result, empty);
}
void Wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;	// make
				Wall(cnt + 1);	// counting
				tmp[i][j] = 0;	// delete
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {	// if it's 0
				for (int k = 0; k < N; k++)
					for (int l = 0; l < M; l++)
						tmp[k][l] = map[k][l];
				tmp[i][j] = 1;	// make
				Wall(1);		// making wall
				tmp[i][j] = 0;	// delete
			}
		}
	}
	cout << result << '\n';
	return 0;
}