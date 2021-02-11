#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int R, C;
char map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
pair<int, int> s, e;
queue<pair<int, int>> water;

void bfs() {
	queue<pair<pair<int, int>, int>> mole;
	mole.push({ {s.first,s.second},0 });
	visited[s.first][s.second] = 1;
	while (!mole.empty()) {
		// 물 먼저
		int curWatersize = water.size();
		for (int i = 0; i < curWatersize; i++) {
			int curx = water.front().first;
			int cury = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				int nx = curx + dx[j];
				int ny = cury + dy[j];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (map[nx][ny] == '.') {
					map[nx][ny] = '*';
					water.push({ nx,ny });
				}
			}
		}
		// 고슴도치 다음
		int curMolesize = mole.size();
		for (int i = 0; i < curMolesize; i++) {
			int curx = mole.front().first.first;
			int cury = mole.front().first.second;
			int result = mole.front().second;
			mole.pop();
			// 목적지 도달
			if (curx == e.first && cury == e.second) {
				cout << result << '\n';
				return;
			}
			for (int j = 0; j < 4; j++) {
				int nx = curx + dx[j];
				int ny = cury + dy[j];
				// 범위를 벗어나는 경우
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				// 이미 방문 || 물 || 돌
				if (visited[nx][ny] || map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
				visited[nx][ny] = 1;
				mole.push({ {nx,ny},result + 1 });
			}
		}
	}
	cout << "KAKTUS" << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') s = { i,j };
			else if (map[i][j] == 'D') e = { i,j };
			else if (map[i][j] == '*') water.push({ i,j });
		}
	}
	bfs();
	return 0;
}