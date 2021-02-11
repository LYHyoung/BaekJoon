#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;
int map[MAX][MAX];
int visited[MAX][MAX];
int dh[8] = { 0,0,-1,1,-1,-1,1,1 };
int dw[8] = { -1,1,0,0,-1,1,-1,1 };
int a, b, NumLand;
void bfs(int h, int w) {
	queue<pair<int, int>> q;
	q.push({ h,w });
	visited[h][w] = 1;
	while (!q.empty()) {
		h = q.front().first;
		w = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nh = h + dh[i];
			int nw = w + dw[i];
			if (nw < 0 || nh < 0 || nw >= a || nh >= b) continue;
			if (map[nh][nw] && !visited[nh][nw]) {
				visited[nh][nw] = true;
				q.push({ nh,nw });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		NumLand = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> a >> b;
		if (!a && !b) break;
		for (int i = 0; i < b; i++)
			for (int j = 0; j < a; j++)
				cin >> map[i][j];
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				if (map[i][j] && !visited[i][j]) {
					NumLand++;
					bfs(i, j);
				}
			}
		}
		cout << NumLand << '\n';
	}
	return 0;
}