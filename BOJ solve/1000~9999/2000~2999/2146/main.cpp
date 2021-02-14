#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 100
using namespace std;

int N, ans;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<pair<int, int>> v;

int Min(int A, int B) { if (A < B) return A; return B; }

void Input() {
	ans = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
				v.push_back({ i,j });
			}
		}
	}
}

void land(int a, int b, int L) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	map[a][b] = L;
	while (q.empty() == 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visited[nx][ny] == 0 && map[nx][ny] == -1) {
					visited[nx][ny] = true;
					map[nx][ny] = L;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int bfs(int L) {
	int result = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == L) {
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
					if (map[nx][ny] != 0 && map[nx][ny] != L) return result;
					else if (map[nx][ny] == 0 && visited[nx][ny] == false) {
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		result++;
	}
}

void Solution() {
	int land_label = 1;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		if (visited[x][y] == false) {
			land(x, y, land_label);
			land_label++;
		}
	}
	for (int i = 1; i < land_label; i++) {
		ans = Min(ans, bfs(i));
		memset(visited, false, sizeof(visited));
	}
	cout << ans << '\n';
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solve();
	return 0;
}