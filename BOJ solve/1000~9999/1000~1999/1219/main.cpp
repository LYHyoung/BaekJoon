#include <iostream>			// 1219
#include <vector>
#include <limits.h>
#define MAX 101
typedef long long ll;
using namespace std;

int N, A, B, M;
vector<pair<int, ll> > adj[MAX];
bool visited[MAX]; 

void DFS(int now) {
	visited[now] = true;
	for (int i = 0; i < adj[now].size(); i++) {
		if (visited[adj[now][i].first] == false) {
			DFS(adj[now][i].first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> A >> B >> M;
	vector<ll> dist(N, LONG_MIN);
	vector<ll> state(N);
	while (M--) {
		int u, v; ll w; cin >> u >> v >> w;
		adj[u].push_back({ v,-w });
	}
	for (int i = 0; i < N; i++) {
		int w; cin >> w;
		state[i] = w;
	}

	DFS(A);
	if (visited[B] == false) {
		cout << "gg" << "\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			adj[i][j].second += state[adj[i][j].first];
		}
	}
	dist[A] = state[A];
	int check = 0;
	for (int k = 0; k <= 2 * N; k++) {
		for (int i = 0; i < N; i++) {
			for (const auto& x : adj[i]) {
				int next = x.first; ll nextcost = x.second;
				if (dist[i] == LONG_MAX) dist[next] = LONG_MAX;
				else if (dist[i] != LONG_MIN && dist[next] < dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k >= N) dist[next] = LONG_MAX;
				}
			}
		}
	}

	if (dist[B] == LONG_MAX) cout << "Gee" << '\n';
	else cout << dist[B] << '\n';
	return 0;
}