#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int los[101];
int d[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		los[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		los[u] = v;
	}
	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx > 100) continue;
			if (los[nx] != 0)
				nx = los[nx];
			if (d[nx] == -1) {
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}
	cout << d[100] << '\n';
	return 0;
}