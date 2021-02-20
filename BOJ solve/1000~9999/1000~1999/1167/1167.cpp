#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

int V;
bool visited[MAX];
vector<pair<int, int>> map[MAX];

int D = 0, fnode = 0;

void DFS(int node, int cost) {
	if (visited[node])
		return;

	visited[node] = true;

	if (D < cost) {
		D = cost;
		fnode = node;
	}

	for (int i = 0; i < map[node].size(); i++)
		DFS(map[node][i].first, cost + map[node][i].second);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V;
	for (int i = 0; i < V; i++) {
		int node; cin >> node;

		while (1) {
			int t; cin >> t;
			if (t == -1) break;
			int cost;  cin >> cost;
			map[node].push_back({ t, cost });
		}
	}
	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	D = 0;
	DFS(fnode, 0);
	
	cout << D << '\n';
	
	return 0;
}