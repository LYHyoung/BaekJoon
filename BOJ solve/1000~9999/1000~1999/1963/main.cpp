#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAX 10000
using namespace std;
int A, B;
bool visited[MAX];
bool EraTos[MAX];		// 소수일 경우 true
void bfs() {
	queue<pair<int, int>> q;
	q.push({ A,0 });
	visited[A] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == B) {
			cout << cnt << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nextcur;
			for (int j = 0; j < 10; j++) {
				string s = to_string(cur);
				s[i] = j + '0';
				nextcur = stoi(s);
				if (EraTos[nextcur] == false) continue;
				if (visited[nextcur] == true) continue;
				if (nextcur >= 10000 || nextcur < 1000) continue;
				visited[nextcur] = true;
				q.push({ nextcur,cnt + 1 });
			}
		}
	}
	cout << "Impossible" << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Tc; cin >> Tc;
	while (Tc--) {
		memset(EraTos, true, sizeof(EraTos));
		for (int i = 2; i < MAX; i++) {
			for (int j = 2; i * j < MAX; j++) {
				EraTos[i * j] = false;
			}
		}
		memset(visited, false, sizeof(visited));
		cin >> A >> B;
		bfs();
	}
	return 0;
}