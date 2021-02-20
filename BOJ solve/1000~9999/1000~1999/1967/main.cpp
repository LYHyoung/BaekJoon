#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 10001
using namespace std;
int n, D = 0, fnode = 0;
bool visited[MAX];
vector<pair<int, int>> map[MAX];
void DFS(int node, int cost) {
	if (visited[node]) return;

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
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int s, e, cost; cin >> s >> e >> cost;
		map[s].push_back({ e,cost });
		map[e].push_back({ s,cost });
	}
	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	D = 0;
	DFS(fnode, 0);
	cout << D << '\n';
	return 0;
}