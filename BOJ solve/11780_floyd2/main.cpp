#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define MAX 110
using namespace std;

int N, M;
int v[MAX][MAX];
int pre[MAX][MAX];
vector<int> route;

void floyd_Warshall() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
					pre[i][j] = k;
				}
			}
}

void find_route(int s, int e) {
	if (pre[s][e] == 0) {
		route.push_back(s);
		route.push_back(e);
		return;
	}
	find_route(s, pre[s][e]);
	route.pop_back();
	find_route(pre[s][e], e);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			v[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int s, e, cost; cin >> s >> e >> cost;
		v[s][e] = min(v[s][e], cost);
	}
	floyd_Warshall();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v[i][j] == INF) cout << 0 << " ";
			else cout << v[i][j] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v[i][j] == INF) cout << 0;
			else {
				route.clear();
				find_route(i, j);
				cout << route.size() << " ";
				for (int k = 0; k < route.size(); k++) cout << route[k] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}