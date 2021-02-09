#include <iostream>
#include <queue>
#include <cstring>
#define MAX 300
using namespace std;
int length;
int s_y, s_x, e_y, e_x;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[8] = { -1,-2,-2,-1,1,2,1,2 };
int dx[8] = { -2,-1,1,2,-2,-1,2,1 };
void bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(s_y, s_x)));
	visited[s_y][s_x]++;
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		if (y == e_y && x == e_x) {
			cout << cnt << '\n';
			return;
		}
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < length && nx < length) {
				if (visited[ny][nx]) continue;
				visited[ny][nx]++;
				q.push(make_pair(cnt+1, make_pair(ny, nx)));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcase; cin >> testcase;
	while (testcase--) {
		memset(visited, false, sizeof(visited));
		cin >> length;
		cin >> s_x >> s_y >> e_x >> e_y;
		bfs();
	}
	return 0;
}