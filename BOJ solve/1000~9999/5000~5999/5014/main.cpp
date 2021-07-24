#include <iostream>
#include <queue>

#define MAX 1000001
using namespace std;

int visited[MAX];
int F, S, G, U, D;

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(S, 0));
	visited[S] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == G) return cnt;

		if (cur + U <= F && visited[cur + U] == 0) {
			q.push(make_pair(cur + U, cnt + 1));
			visited[cur + U] = 1;
		}
		if (cur - D > 0 && visited[cur - D] == 0) {
			visited[cur - D] = 1;
			q.push(make_pair(cur - D, cnt + 1));
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	int ans = bfs();
	if (ans == -1)
		cout << "use the stairs" << '\n';
	else 
		cout << ans << '\n';
	return 0;
}