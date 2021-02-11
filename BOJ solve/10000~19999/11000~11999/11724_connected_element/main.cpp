#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1000+1
using namespace std;
int N, M;
vector<int> map[MAX];
bool visited[MAX];
void bfs(int num) {
	queue<int> q;
	q.push(num);
	visited[num] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < map[cur].size(); i++) {
			int nextcur = map[cur][i];
			if (!visited[nextcur]) {
				visited[nextcur] = true;
				q.push(nextcur);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e; cin >> s >> e;
		map[s].push_back(e);
		map[e].push_back(s);
	}
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
			bfs(i);
		}
	}
	cout << cnt;
	return 0;
}