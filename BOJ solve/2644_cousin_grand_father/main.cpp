#include <iostream>
#include <queue>
#define MAX 100+1
using namespace std;
int n, s, e;
int map[MAX][MAX];
int visited[MAX];
void bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e) break;
		for (int i = 1; i <= n; i++) {
			if (map[cur][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = visited[cur] + 1;
			}
		}
	}
	cout << visited[e] - 1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int forn;
	cin >> n >> s >> e >> forn;
	for (int i = 0; i < forn; i++) {
		int u, v; cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
	bfs();
	return 0;
}