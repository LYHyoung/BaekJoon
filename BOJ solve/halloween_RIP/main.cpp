#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define MAX 900
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int W, H, G, E;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pii> adj[MAX + 1];	// adj[i] : i에서 갈 수 있는 pair<위치, 시간>
vector<int> dist(MAX + 1, INF);
set<int> RIP;	// 무덤
int main() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		RIP.clear();
		for (int i = 0; i <= MAX; i++) {
			dist[i] = INF;
			adj[i].clear();
		}
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		int NUM = W * H;
		cin >> G;
		for (int i = 0; i < G; i++) {
			int x, y;
			cin >> x >> y;
			RIP.insert(y * W + x);
		}
		cin >> E;
		for (int i = 0; i < E; i++) {
			int x1, x2, y1, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			int start = y1 * W + x1;
			int end = y2 * W + x2;
			adj[start].push_back(pii(end, t));
		}
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < H; j++) {
				int start = j * W + i;
				if (RIP.count(start)) continue;
				if (!adj[start].empty()) continue;
				if (start == NUM - 1) continue;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
					int next = ny * W + nx;
					if (RIP.count(next)) continue;
					adj[start].push_back(pii(next, 1));
				}
			}
		}
		dist[0] = 0;
		int check = 0;
		for (int k = 0; k <= NUM; k++) {
			for (int i = 0; i < NUM; i++) {
				if (dist[i] == INF) continue;
				for (auto x : adj[i]) {
					if (dist[x.first] > dist[i] + x.second) {
						if (k == NUM) check++;
						dist[x.first] = dist[i] + x.second;
					}
				}
			}
		}
		if (check) cout << "Never" << '\n';
		else if (dist[NUM - 1] == INF) cout << "Impossible" << '\n';
		else cout << dist[NUM - 1] << '\n';
	}
	return 0;

	return 0;
}