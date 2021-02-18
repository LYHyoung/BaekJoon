#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> Next_q;

bool check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) return false;
		}
	}
	return true;
}

void Melt() {
	queue<pair<int, int>> q = Next_q;
	while (!Next_q.empty()) Next_q.pop();
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = 0;
				Next_q.push({ nx,ny });
			}
		}
	}
}

void Hole_check() {		// 내부 공기와 외부 공기 합치는 과정
	queue<pair<int, int>> q = Next_q;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				Next_q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// Input
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				visited[i][j] = -1;
		}
	}

	// 내부 공기와 외부 공기 분리
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visited[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (map[nx][ny] == 0 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	// 외부 공기 중 치즈와 인접한 공기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
					if (map[nx][ny] == 1) {
						Next_q.push({ i,j });
						break;
					}
				}
			}
		}
	}

	int time = 0;
	int size = 0;

	while (1) {
		if (check() == true) break;

		Melt();
		size = Next_q.size();

		Hole_check();
		time++;
	}

	cout << time << '\n' << size << '\n';

	return 0;
}