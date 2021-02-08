#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 100000+1
#define INF 1e9
using namespace std;
int visited[MAX];
int N, K;
void bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == K) return;		// 어차피 가장 작은 값이 리턴될 것이다.

		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			q.push(cur - 1);
			visited[cur - 1] = visited[cur] + 1;
		}
		if (cur + 1 <= MAX - 1 && visited[cur + 1] == 0) {
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
		if (cur * 2 <= MAX - 1 && visited[2 * cur] == 0) {
			q.push(2 * cur);
			visited[2 * cur] = visited[cur] + 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	bfs();
	cout << visited[K] << '\n';
	return 0;
}