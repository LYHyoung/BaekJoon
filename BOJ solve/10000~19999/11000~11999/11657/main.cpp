#include <iostream>			// 11657
#include <vector>
#define INF 987654321
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<pair<int, int>>> adj(N + 1);
	vector<long long> dist(N + 1, INF);
	dist[1] = 0;
	while (M--) {
		int A, B, C; cin >> A >> B >> C;
		adj[A].push_back({ B,C });
	}
	int check = 0;
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int start = i;
				int cur = adj[i][j].first;
				int cost = adj[i][j].second;
				if (dist[i] != INF && dist[cur] > dist[start] + cost) {
					dist[cur] = dist[start] + cost;
					if (k == N) {
						check++;
						break;
					}
				}
			}
		}
	}
	if (check) cout << -1 << '\n';
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	return 0;
}