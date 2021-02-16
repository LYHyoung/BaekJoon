#include <iostream>
#include <queue>
#define MAX 100001
#define INF 1e9
using namespace std;
int N, K;
int visited[MAX];
int bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == K) return visited[K];
		if (cur + 1 < MAX && visited[cur + 1] > visited[cur] + 1) {
			visited[cur + 1] = visited[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && visited[cur - 1] > visited[cur] + 1) {
			visited[cur - 1] = visited[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 < MAX && visited[cur * 2] > visited[cur]) {
			visited[cur * 2] = visited[cur];
			q.push(cur * 2);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < MAX; i++)
		visited[i] = INF;
	int ans = bfs();
	cout << ans - 1 << '\n';
	return 0;
}