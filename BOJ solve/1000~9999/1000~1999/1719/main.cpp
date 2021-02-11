/*
#include <iostream>
#include <queue>
#define MAX 200
#define INF 10000
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	int MAP[MAX][MAX];
	int ans[MAX];
	int dist[MAX];

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			MAP[i][j] = INF;
		}
		dist[i] = INF;
		ans[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int a, b, length;
		cin >> a >> b >> length;
		MAP[a][b] = length;
		MAP[b][a] = length;
	}
	
	for (int i = 1; i <= n; i++) {
		priority_queue<pair<int, int>> PQ;
		dist[i] = 0;	// 자기자신
		PQ.push({ dist[i],i });
		
		while (PQ.empty() == 0) {
			int d = -PQ.top().first;
			int e = PQ.top().second;
			PQ.pop();
			for (int j = 1; j <= n; j++) {
				if (MAP[e][j] == INF) continue;
				if (dist[j] > dist[e] + MAP[e][j]) {
					dist[j] = dist[e] + MAP[e][j];
					ans[j] = e;
					PQ.push(make_pair(dist[j], j));
				}
			}
		}

		for (int k = 1; k <= n; k++) {
			int t = k;
			while (ans[t] != i) {
				if (ans[t] == INF) {
					cout << "- ";
					break;
				}
				t = ans[k];
			}
			cout << t << " ";
		}
		cout << '\n';
	}

	return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define INF 10000
#define MAX 201
using namespace std;

int dist[MAX];
int p[MAX];
int n, m, a, b, c;

struct store {
	int cur;
	int cost;
};

vector<store> v[MAX];

struct cmp {
	bool operator()(const store &a, const store &b){
		return a.cost > b.cost;
	}
};

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	priority_queue<store, vector<store>, cmp> PQ;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[j] = INF;
		dist[i] = 0;
		PQ.push({ i,dist[i] });
		while (!PQ.empty()) {
			store cur = PQ.top();
			int c_node = cur.cur;
			PQ.pop();
			for (int j = 0; j < v[c_node].size(); j++) {
				store next = v[c_node][j];		//
				int n_node = next.cur;
				int n_cost = next.cost;

				if (dist[n_node] > dist[c_node] + n_cost) {
					dist[n_node] = dist[c_node] + n_cost;
					p[n_node] = c_node;
					PQ.push({ n_node, dist[n_node] });
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			if (k == i) {
				printf("- ");
			}
			else if (p[k] == i) {
				printf("%d ", k);
			}
			else {
				int current = k;
				while (1) {
					if (p[current] == i) {
						printf("%d ", current);
						break;
					}
					else {
						current = p[current];
					}
				}
			}
		}
		printf("\n");
	}
}