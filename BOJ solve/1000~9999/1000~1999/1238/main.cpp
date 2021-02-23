#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M, X, ans;
int dist[MAX], rev[MAX];
vector<pair<int, int>> v[MAX];

// 다익스트라
void DIJK(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({0,start});
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nextcost = v[cur][i].first;
			int nextcur = v[cur][i].second;
			if (dist[nextcur] > cost + nextcost) {
				dist[nextcur] = cost + nextcost;
				pq.push({ dist[nextcur], nextcur });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int s, e, cost; cin >> s >> e >> cost;
		v[s].push_back({ cost,e });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) dist[j] = INF;
		DIJK(i);
		rev[i] = dist[X];
	}

	for (int i = 1; i <= N; i++) dist[i] = INF;
	DIJK(X);
	for (int i = 1; i <= N; i++) rev[i] = rev[i] + dist[i];
	sort(rev + 1, rev + N + 1);
	ans = rev[N];

	cout << ans << '\n';

	return 0;
}