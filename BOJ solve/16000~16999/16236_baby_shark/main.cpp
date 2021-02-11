#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 20
using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct {
	int x, y;
	int size;
	int Eat_Num;
	int Time;
}Shark;

typedef struct {
	int x, y;
	int Dist;
}Fish;

Shark S;
vector<Fish> v;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				S.x = i;
				S.y = j;
				S.size = 2;
				S.Eat_Num = 0;
				S.Time = 0;
			}
		}
	}
}

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x,y},0 });
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] == 0) {
				if (map[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push({ { nx,ny }, dist + 1 });
				}
				else if (map[nx][ny] < S.size) {
					Fish t;
					t.x = nx;
					t.y = ny;
					t.Dist = dist + 1;

					v.push_back(t);
					visited[nx][ny] = 1;
					q.push({ {nx,ny},dist + 1 });
				}
				else if (map[nx][ny] == S.size) {
					visited[nx][ny] = 1;
					q.push({ {nx,ny},dist + 1 });
				}
			}
		}
	}
}

bool Personal_Sort(Fish A, Fish B) {
	if (A.Dist <= B.Dist) {
		if (A.Dist == B.Dist) {
			if (A.x <= B.x) {
				if (A.x == B.x) {
					if (A.y < B.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void Solution() {
	while (1) {
		v.clear();
		memset(visited, false, sizeof(visited));
		bfs(S.x, S.y);
		if (v.size() == 0) {
			cout << S.Time << '\n';
			break;
		}
		/*
		else if (v.size() == 1) {
			map[v[0].x][v[0].y] = 9;
			map[S.x][S.y] = 0;
			S.x = v[0].x;
			S.y = v[0].y;
			S.Eat_Num++;
			S.Time = S.Time + v[0].Dist;
			if (S.Eat_Num == S.size) {
				S.Eat_Num = 0;
				S.size++;
			}
		}*/
		else {
			sort(v.begin(), v.end(), Personal_Sort);
			map[v[0].x][v[0].y] = 9;
			map[S.x][S.y] = 0;
			S.x = v[0].x;
			S.y = v[0].y;
			S.Eat_Num++;
			S.Time = S.Time + v[0].Dist;
			if (S.Eat_Num == S.size) {
				S.Eat_Num = 0;
				S.size++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Input();

	Solution();

	return 0;
}