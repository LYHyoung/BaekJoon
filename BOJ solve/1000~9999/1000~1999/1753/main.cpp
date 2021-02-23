#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20001
#define INF 1e9
using namespace std;

int V, E;
int dist[MAX];
vector<pair<int, int>> v[MAX];

void DIJK(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int nextcost = v[cur][i].first;
			int nextcur = v[cur][i].second;
			if (dist[nextcur] > cost + nextcost) {
				dist[nextcur] = cost + nextcost;
				pq.push({ dist[nextcur],nextcur });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int K;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int s, e, cost; cin >> s >> e >> cost;
		v[s].push_back({ cost,e });
	}

	for (int i = 1; i <= V; i++) dist[i] = INF;

	DIJK(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
	return 0;
}