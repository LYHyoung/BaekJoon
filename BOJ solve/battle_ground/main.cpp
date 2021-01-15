#include <iostream>			// 14938
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;

vector<pair<int, int>> v[MAX];

int dist[MAX];
int p[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;
	int ans;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {		// initialize 'place'
		cin >> p[i];
	}
	
	for (int i = 0; i < r; i++) {		// initialize 'v'
		int s, e, length;
		cin >> s >> e >> length;
		v[s].push_back({ e,length });
		v[e].push_back({ s,length });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) dist[j] = INF;		// making dist array

		dist[i] = 0;		// start vertex's distance

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
		PQ.push({ dist[i],i });
		while (PQ.empty() == 0) {
			int cur = PQ.top().first;
			int city = PQ.top().second;
			PQ.pop();
			for (int k = 0; k < v[city].size(); k++) {
				int nextdist = v[city][k].second + cur;
				int nextcity = v[city][k].first;
				if (nextdist > m) continue;
				if (dist[nextcity] > nextdist) {
					dist[nextcity] = nextdist;
					PQ.push({ nextdist, nextcity });
				}
			}
		}

		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m) {
				temp += p[j];
			}
		}
		ans = max(ans,temp);
	}
	cout << ans;
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, R, res;
int t[110];
vector<pair<int, int>> v[110]; // v[a] = (c,b) : a에서 b까지 c의 거리로 이동 가능
int dist[110];

void dijk(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push({ 0,start }); //거리, 도시
	while (!q.empty()) {
		int cur = q.top().first;
		int city = q.top().second;
		q.pop();
		for (int i = 0; i < v[city].size(); i++) {
			int nextDist = v[city][i].first + cur;
			int nextCity = v[city][i].second;
			if (nextDist > M) continue; //거리가 M이상이면 건너뛴다.
			if (dist[nextCity] > nextDist) {
				dist[nextCity] = nextDist;
				q.push({ nextDist, nextCity });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) cin >> t[i];
	for (int a, b, c, i = 1; i <= R; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) dist[j] = 987654321; // 거리 초기화

		dijk(i); // i 도시에서 시작하는 다익스트라

		int tmp = 0;
		for (int j = 1; j <= N; j++)
			if (dist[j] <= M) tmp += t[j]; // 얻을 수 있는 아이템 수 계산

		res = max(res, tmp);
	}
	cout << res;
}*/