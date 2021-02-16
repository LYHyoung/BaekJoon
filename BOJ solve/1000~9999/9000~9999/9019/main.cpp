#include <iostream>
#include <queue>
#include <cstring>
#define MAX 10001
using namespace std;
int A, B;
bool visited[MAX];
string bfs(int start) {
	queue<pair<int, string>> q;
	q.push({ start,"" });
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front().first;
		string s = q.front().second;
		q.pop();
		
		if (x == B) return s;

		int nx = x * 2;
		if (nx > 9999) nx = nx % 10000;

		if (visited[nx] == false) {
			visited[nx] = true;
			q.push({ nx,s + "D" });
		}

		nx = x - 1;
		if (nx < 0) nx = 9999;
		if (visited[nx] == false) {
			visited[nx] = true;
			q.push({ nx,s + "S" });
		}

		nx = (x % 1000) * 10 + (x / 1000);
		if (visited[nx] == false) {
			visited[nx] = true;
			q.push({ nx,s + "L" });
		}

		nx = (x % 10) * 1000 + (x / 10);
		if (visited[nx] == false) {
			visited[nx] = true;
			q.push({ nx,s + "R" });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> A >> B;
		memset(visited, false, sizeof(visited));
		string ans = bfs(A);
		cout << ans << '\n';
	}
	return 0;
}