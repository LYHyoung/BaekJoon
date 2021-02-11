#include <iostream>
#include <vector>
#define MAX 100
#define INF 1e9
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n; cin >> m;
	vector<vector<int>> adj(n);
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adj[i].push_back(INF);
	
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		if (adj[u-1][v-1] > w)
			adj[u - 1][v - 1] = w;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nextcost = adj[i][j];
				if (nextcost > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || adj[i][j] == INF)
				cout << 0 << " ";
			else
				cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}