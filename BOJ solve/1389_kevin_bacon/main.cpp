/*
#include <iostream>
#define MAX 100
#define INF 1e9
using namespace std;
int adj[MAX][MAX];
int dist[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		adj[u - 1][v - 1] = 1;
		adj[v - 1][u - 1] = 1;
		dist[u - 1][v - 1] = 1;
		dist[v - 1][u - 1] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (adj[i][k] && adj[k][j]) {
					if (dist[i][j] > 2) dist[i][j] = 2;	 // 2단계
					continue;
				}
				for (int a = 0; a < N; a++) {
					if (adj[i][k] && adj[k][a] && adj[a][j]) {	// 3단계
						if (dist[i][j] > 3) dist[i][j] = 3;
						continue;
					}
					for (int b = 0; b < N; b++) {
						if (adj[i][k] && adj[k][a] && adj[a][b] && adj[b][j]) {	// 4단계
							if (dist[i][j] > 4)dist[i][j] = 4;
							continue;
						}
						for (int c = 0; c < N; c++) {
							if (adj[i][k] && adj[k][a] && adj[a][b] && adj[b][c] && adj[c][j]) {	// 5단계
								if (dist[i][j] > 5) dist[i][j] = 5;
								continue;
							}
						}
					}
				}
			}
		}
	}
	int arr;
	int leng = INF;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			temp += dist[i][j];
		}
		if (leng > temp) {
			leng = temp;
			arr = i;
		}
	}
	cout << arr + 1;
	return 0;
}
*/
#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;
int N, M;
int adj[MAX][MAX];
void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (adj[i][k] && adj[k][j]) {
					if (!adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
					else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (M--) {
		int s, e; cin >> s >> e;
		adj[s][e] = adj[e][s] = 1;
	}
	floyd();
	int arr;
	int leng = INF;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp += adj[i][j];
		}
		if (leng > temp) {
			leng = temp;
			arr = i;
		}
	}
	cout << arr;
	return 0;
}