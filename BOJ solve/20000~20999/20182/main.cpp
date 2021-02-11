#include <iostream>		// 20182
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
#define INF 0x3f3f3f3f3f3f3f3fLL
typedef long long ll;
using namespace std;
int N, M, a, b, c;
vector<pair<int, ll>> adj[MAX];
vector<ll> cand;
int cango(ll x) {
	vector<ll> dist(N + 1, INF);
	priority_queue < pair<ll, pair<int, int> > > PQ;
	PQ.push({ 0,{a,0} });
	while (!PQ.empty()) {
		ll cost = -PQ.top().first;
		int cur = PQ.top().second.first;
		int maxv = PQ.top().second.second;
		PQ.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			ll nextcost = adj[cur][i].second;
			if (nextcost <= x && dist[next] > nextcost + cost) {
				dist[next] = cost + nextcost;
				int t = max(maxv, (int)nextcost);
				PQ.push({ -dist[next],{next,max(maxv, t)} });
			}
		}
	}
	return (dist[b] <= c ? 1 : 0);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> a >> b >> c;
	for (int i = 0; i < M; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
		cand.push_back(w);
	}
	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());
	int r = cand.size(); int ans = -1;
	int l = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (cango(cand[m])) {
			r = m - 1; ans = cand[m];
		}
		else l = m + 1;
	}
	cout << ans;
	return 0;
}
/*
#include <iostream>			// 20182
#include <vector>
#include <queue>

#define INF 987654321
#define MAX 11
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, A, B, C;
	cin >> N >> M >> A >> B >> C;
	vector<pair<int, int>> adj[MAX];
	pair<int,int> dist[MAX];		// ±Ê¿Ã, max
	int dmax = -1;
	for (int i = 1; i <= N; i++) {
		dist[i].first = INF;
		dist[i].second = -1;
	}
	while (M--) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ v,d });
		adj[v].push_back({ u,d });
	}
	priority_queue<pair<int, pair<int, int> > > PQ;
	PQ.push({ 0,{A,-1} });
	dist[A].first = 0;
	int temp = 0;
	while (!PQ.empty()) {
		int cost = -PQ.top().first;
		int cur = PQ.top().second.first;
		int m = PQ.top().second.second;
		PQ.pop();
		if (dist[cur].first < cost) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int nextcur = adj[cur][i].first;
			int nextcost = adj[cur][i].second;
			if (dist[nextcur].first > nextcost + cost && C >= nextcost + cost) {
				dist[nextcur].first = nextcost + cost;
				if (nextcost > m) {
					m = nextcost;
					dist[nextcur].second = m;
				}
				PQ.push({ -dist[nextcur].first,{nextcur,m} });
			}
		}
	}
	cout << dist[B].second << '\n';
	return 0;
}
*/