#include <iostream>			// 1865
#include <vector>
#define INF 987654321
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TC; cin >> TC;
	while (TC--) {
		int N, M, W; cin >> N >> M >> W;
		vector<vector<pair<int, int>>> adj(N + 1);
		vector<int> dist(N + 1, INF);
		dist[1] = 0;
		while (M--) {
			int S, E, T; cin >> S >> E >> T;
			adj[S].push_back({ E,T });
			adj[E].push_back({ S,T });
		}
		while (W--) {
			int S, E, T; cin >> S >> E >> T;
			adj[S].push_back({ E,(-1) * T });		// -를 붙일때 사용
		}
		int ans = 0;
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				int adjsize = adj[i].size();
				for (int j = 0; j < adjsize; j++) {
					int start = i;
					int end = adj[i][j].first;
					int nextcost = adj[i][j].second;
					if (dist[end] > dist[start] + nextcost) {
						dist[end] = dist[start] + nextcost;
						if (k == N) ans = 1;
					}
				}
			}
		}
		ans ? cout << "YES" << '\n' : cout << "NO" << '\n';		// 기억해두기
	}
	return 0;
}
