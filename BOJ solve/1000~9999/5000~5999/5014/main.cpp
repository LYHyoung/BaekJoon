#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;
int visited[MAX];
int F, S, G, U, D;
void bfs() {
	queue<int> q;
	q.push(S);
	visited[S] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == G)			// µµÂø ¿Ï·á
			break;
		if (cur + U > F)		// FÃþ À§
			continue;
		else if (visited[cur + U] == 0) {
			q.push(cur + U);
			visited[cur + U] = visited[cur] + 1;
		}
		if (cur - D < 1)		// 1Ãþ ¾Æ·¡
			continue;
		else if (visited[cur - D] == 0) {
			visited[cur - D] = visited[cur] + 1;
			q.push(cur - D);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	bfs();
	if (visited[G] == 0)
		cout << "use the stairs" << '\n';
	else 
		cout << visited[G] - 1 << '\n';
	return 0;
}