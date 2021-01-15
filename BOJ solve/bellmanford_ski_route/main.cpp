#include <iostream>			//	16064
#include <vector>
#include <algorithm>
#define MAX 1001
#define INF 987654321
using namespace std;

int dist[MAX][MAX];
int ans;

int floyd(int N) {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (dist[i][k] == INF) continue;
			for (int j = 1; j <= N; j++) {
				if (dist[k][j] == INF) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					ans = min(ans, dist[i][j]);
				}
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = INF;
	for (int i = 0; i < M; i++) {
		int u, v, w; cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], -w);
		ans = min(dist[u][v], ans);
	}
	cout << -floyd(N);;
	return 0;
}