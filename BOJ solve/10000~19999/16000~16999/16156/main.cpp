/*
#include <iostream>			// 16156
#include <vector>
#include <queue>
#define MAX 501
#define INF 987654321
using namespace std;
int dx[4] = { 0,0,-1,1 }; int dy[4] = { 1,-1,0,0 };
int N, M;
int mat[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<pair<int, int>> adj[MAX];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int w; cin >> w;
			adj[i].push_back({ j,w });
		}
	}
	
	for (int i = 1; i <= N; i++) {
		int dist[MAX][MAX];
		for (int j = 1; j <= N; j++) for (int k = 1; k <= M; k++) dist[j][k] = INF;
		priority_queue<pair<int, pair<int, int> > > PQ;
		PQ.push({ 0,{i,1} });
		dist[i][1] = 0;
		while (!PQ.empty()) {
			int cur_x = PQ.top().second.first;
			int cur_y = PQ.top().second.second;
			int cost = -PQ.top().first;
			PQ.pop();
			if (dist[cur_x][cur_y] < cost) continue;
			for (int j = 0; j < 4; j++) {
				int n_x = dx[j] + cur_x;
				int n_y = dy[j] + cur_y;
				if (n_x <= 0 || n_y <= 0 || n_x > N || n_y > M) continue;
				int nextcost = adj[n_x][n_y - 1].second;
				if (dist[n_x][n_y] > cost + nextcost) {
					dist[n_x][n_y] = cost + nextcost;
					PQ.push({ -dist[n_x][n_y],{n_x,n_y} });
				}
			}
		}
		int mi = INF;
		int idx;
		for (int j = 1; j <= N; j++) {
			if (mi > dist[j][M]) {
				mi = dist[j][M];
				idx = j;
			}
		}
		cout << "mi : " << mi << ", idx : " << idx << '\n';
		mat[idx]++;
	}
	for (int i = 1; i <= N; i++) {
		cout << mat[i] << '\n';
	}
	return 0;
}			// time over
*/
#include <iostream>			// 16156
#include <vector>
#include <queue>
#include <memory.h>			// memset
#define MAX 501
using namespace std;
struct node {
	int x, y, c, p;
	bool operator < (const node& n) const {
		return n.c < c;
	}
};
int dx[4] = { 0,0,-1,1 }; int dy[4] = { 1,-1,0,0 };
int dist[MAX][MAX];
int adj[MAX][MAX];
int ans[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)	cin >> adj[i][j];
	memset(dist, 127, sizeof(dist));
	priority_queue<node> PQ;
	for (int i = 0; i < N; i++) {
		PQ.push({ i,M - 1,adj[i][M - 1],i });
		dist[i][M - 1] = adj[i][M - 1];
	}
	node t;
	while (!PQ.empty()) {
		t = PQ.top();
		PQ.pop();
		if (dist[t.x][t.y] < t.c) continue;
		if (t.y == 0) ans[t.p]++;
		for (int i = 0; i < 4; i++) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] > t.c + adj[nx][ny]) {
				dist[nx][ny] = t.c + adj[nx][ny];
				PQ.push({ nx,ny,dist[nx][ny],t.p });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}