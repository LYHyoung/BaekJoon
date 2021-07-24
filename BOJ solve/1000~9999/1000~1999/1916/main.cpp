#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M;
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

		if (dist[cur] < cost) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nextcur = v[cur][i].second;
			int nextcost = v[cur][i].first;
			if (dist[nextcur] > cost + nextcost) {
				dist[nextcur] = cost + nextcost;
				pq.push({ dist[nextcur],nextcur });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, cost; cin >> s >> e >> cost;
		v[s].push_back({ cost,e });
	}
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	int s, e; cin >> s >> e;
	DIJK(s);

	cout << dist[e] << '\n';

	return 0;
}