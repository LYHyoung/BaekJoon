#include <iostream>			// E > V : 프림(Prim), V > E : 크루스칼(Kruskal)
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

typedef struct kruskal {
	int from;
	int to;
	int cost;
}KS;

vector<KS> edge;

int parent[MAX];
int ans;
bool chk;

bool comp(KS d1, KS d2) {
	return d1.cost < d2.cost;
}

// Union Find
int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

// Union Find
void merge(int u, int v) {
	chk = false;
	u = find(u);
	v = find(v);

	if (u == v)		// 사이클 존재 여부 확인
		return;

	parent[u] = v;
	chk = true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E; cin >> V >> E;
	
	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		KS ks;
		cin >> ks.from >> ks.to >> ks.cost;
		edge.push_back(ks);
	}
	sort(edge.begin(), edge.end(), comp);

	for (int i = 0; i < E; i++) {
		merge(edge[i].from, edge[i].to);
		if (chk)
			ans += edge[i].cost;
	}

	cout << ans << '\n';

	return 0;
}