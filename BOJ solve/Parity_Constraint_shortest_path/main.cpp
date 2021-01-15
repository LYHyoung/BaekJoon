#include <iostream>			// 20128
#include <vector>
#include <queue>
#define MAX 100001
#define INF 1e18
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<pair<int, ll>> adj[MAX];
	ll dist_odd[MAX];
	ll dist_even[MAX];
	for (int i = 1; i <= N; i++) {
		dist_odd[i] = INF;
		dist_even[i] = INF;
	}
	while (M--) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	priority_queue<pair<ll, int>> PQ;
	PQ.push({ 0,1 });
	dist_even[1] = 0;
	while (!PQ.empty()) {
		int cur = PQ.top().second;
		ll cost = -PQ.top().first;
		PQ.pop();
		// if(cost != ~~ ) continue 랑 if(cost > ~~ ) continue 다익스트라에서는 동치라고 볼수있지 않을까 
		if (cost != dist_even[cur] && cost != dist_odd[cur]) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int nextcur = adj[cur][i].first;
			ll nextcost = adj[cur][i].second;
			if ((cost + nextcost) % 2 == 0) {
				if (dist_even[nextcur] > cost + nextcost) {
					dist_even[nextcur] = cost + nextcost;
					PQ.push({ -dist_even[nextcur], nextcur });
				}
			}
			else {
				if (dist_odd[nextcur] > cost + nextcost) {
					dist_odd[nextcur] = cost + nextcost;
					PQ.push({ -dist_odd[nextcur], nextcur });
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist_odd[i] == INF) cout << -1 << " ";
		else cout << dist_odd[i] << " ";
		if (dist_even[i] == INF) cout << -1 << '\n';
		else cout << dist_even[i] << '\n';
	}
	return 0;
}