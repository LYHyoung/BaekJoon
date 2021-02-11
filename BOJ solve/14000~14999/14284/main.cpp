#include <iostream>			// 14284
#include <vector>
#include <queue>
#define MAX 5001
#define INF 987654321
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int dist[MAX];
	vector<pair<int, int>> v[MAX];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int s, t;
	cin >> s >> t;
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	PQ.push({ 0,s });
	while (!PQ.empty()) {
		int cost = PQ.top().first;
		int idx = PQ.top().second;
		PQ.pop();
		if (dist[idx] < cost) continue;
		for (int i = 0; i < v[idx].size(); i++) {
			int nextidx = v[idx][i].first;
			int nextcost = v[idx][i].second;
			if (dist[nextidx] > cost + nextcost) {
				dist[nextidx] = cost + nextcost;
				PQ.push({ dist[nextidx],nextidx });
			}
		}
	}
	cout << dist[t] << '\n';
	return 0;
}