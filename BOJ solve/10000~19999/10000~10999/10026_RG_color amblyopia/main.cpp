#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std; 
int N;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visited[nx][ny] == 0) {
					if (map[nx][ny] == map[x][y]) {
						visited[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int cnt_nor = 0, cnt_amb = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				bfs(i, j);
				cnt_nor++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				bfs(i, j);
				cnt_amb++;
			}
		}
	}
	cout << cnt_nor << " " << cnt_amb << '\n';
	return 0;
}