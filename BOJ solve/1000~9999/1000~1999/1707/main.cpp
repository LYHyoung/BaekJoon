#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 20000+1
#define RED 1
#define BLUE 2
using namespace std;
int V, E;
int visited[MAX];
vector<int> map[MAX];
void bfs(int start) {
	queue<int> q;
	int color = RED;
	visited[start] = color;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visited[cur] == RED) {
			color = BLUE;
		}
		else if (visited[cur] == BLUE) {
			color = RED;
		}
		for (int i = 0; i < map[cur].size(); i++) {
			int nextcur = map[cur][i];
			if (!visited[nextcur]) {
				visited[nextcur] = color;
				q.push(nextcur);
			}
		}
	}
}
bool check() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			int nextcur = map[i][j];
			if (visited[i] == visited[nextcur]) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K; cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int s, e; cin >> s >> e;
			map[s].push_back(e);
			map[e].push_back(s);
		}
		for (int i = 1; i <= V; i++) {
			if (!visited[i])
				bfs(i);
		}
		if (check()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		for (int i = 0; i <= V; i++) {
			map[i].clear();
		}
		memset(visited, false, sizeof(visited));
	}
	return 0;
}