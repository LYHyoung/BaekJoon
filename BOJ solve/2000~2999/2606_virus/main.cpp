#include <iostream>
#include <queue>
#define MAX 100+1
#define INF 1e9
using namespace std;
bool map[MAX][MAX];
bool cnt[MAX];
int N, M;
void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!map[s][i]) continue;
			if (cnt[i]) continue;
			cnt[i] = true;
			q.push(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	/*
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = INF;
	*/
	for (int i = 1; i <= M; i++) {
		int s, e; cin >> s >> e;
		map[s][e] = map[e][s] = true;
	}
	bfs();
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i]) ans++;
	}
	cout << ans - 1;
	return 0;
}