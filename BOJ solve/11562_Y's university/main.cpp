#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 251
#define INF 1e9
using namespace std;

int map[MAX][MAX];
//int cost[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) map[i][j] = INF;
			else map[i][j] = 0;
		}
	}
	while (m--) {
		int u, v, b; cin >> u >> v >> b;
		map[u][v] = 0;
		map[v][u] = (b == 0 ? 1 : 0);			// good idea
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int s, e; cin >> s >> e;
		cout << map[s][e] << '\n';
	}
	return 0;
}