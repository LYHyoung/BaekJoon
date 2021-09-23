#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int r, c;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

pair<int, int> start;

char map[MAX][MAX];
int fire_map[MAX][MAX];
bool visit[MAX][MAX];

queue<pair<int, int>> fire_q;

void fire_map_make(int a, int b) {
	while (!fire_q.empty()) {
		int qsize = fire_q.size();
		for (int s = 0; s < qsize; s++) {
			int x = fire_q.front().first;
			int y = fire_q.front().second;
			fire_q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
					if (map[nx][ny] != '#') {
						if (fire_map[nx][ny] > fire_map[x][y] + 1) {
							fire_map[nx][ny] = fire_map[x][y] + 1;
							fire_q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}

int mv_person(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == 0 || y == 0 || x == r - 1 || y == c - 1) return cnt + 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (map[nx][ny] != '#' && visit[nx][ny] == false) {
					if (fire_map[nx][ny] > cnt + 1) {
						visit[nx][ny] = true;
						q.push({ {nx,ny},cnt + 1 });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			bool fire = false;
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				start.first = i;
				start.second = j;
			}
			else if (map[i][j] == 'F') {
				fire_q.push({ i,j });
				fire_map[i][j] = 0;
				fire = true;
			}
			if (fire == false) fire_map[i][j] = 987654321;
		}
	}

	fire_map_make(0, 0);

	int chk = mv_person(start.first, start.second);
	if (chk == -1) cout << "IMPOSSIBLE" << '\n';
	else cout << chk << '\n';

	return 0;
}