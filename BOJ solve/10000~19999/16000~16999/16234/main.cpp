#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 50+1
using namespace std;

int N, L, R;
int A[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check = true;

bool LR(int x, int y, int nx, int ny) {
	if (L <= abs(A[x][y] - A[nx][ny]) && abs(A[x][y] - A[nx][ny]) <= R) return true;
	return false;
}

bool LR_2(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
			if (L <= abs(A[x][y] - A[nx][ny]) && abs(A[x][y] - A[nx][ny]) <= R)
				return true;
	}
	return false;
}

void bfs(int a, int b) {
	queue<pair<int, int>> q, Nq;
	q.push({ a,b });
	Nq.push({ a,b });
	visited[a][b] = 1;
	int sum = 0;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sum += A[x][y];
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (visited[nx][ny] != 0) continue;
			if (LR(x, y, nx, ny)) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
				Nq.push({ nx,ny });
			}
		}
	}
	int Val = sum / cnt;
	while (!Nq.empty()) {
		int x = Nq.front().first;
		int y = Nq.front().second;
		Nq.pop();
		A[x][y] = Val;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	int cnt = 0;
	while (check) {
		check = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j] == 0 && LR_2(i,j)) {
					bfs(i,j);
					check = true;
				}
			}
		}
		if (check) cnt++;
		memset(visited, false, sizeof(visited));
	}
	cout << cnt << '\n';
	return 0;
}