#include <iostream>			//5972
#include <vector>
#include <queue>
#define MAX 50001
#define INF 987654321
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	int dist[MAX];
	for (int i = 1; i <= N; i++) dist[i] = INF;
	vector<pair<int, int>> v[MAX];
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	PQ.push({ 0,1 });
	while (!PQ.empty()) {
		int cost = PQ.top().first;
		int idx = PQ.top().second;
		PQ.pop();
		if (dist[idx] < cost) continue;
		for (int i = 0; i < v[idx].size(); i++) {
			int nextidx = v[idx][i].first;
			int nextcost = v[idx][i].second;
			if (dist[nextidx] > nextcost + cost) {
				dist[nextidx] = nextcost + cost;
				PQ.push({ dist[nextidx],nextidx });
			}
		}
	}
	cout << dist[N] << '\n';
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> arr[50001];
int dp[50001];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = INF;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	dp[1] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if (dp[idx] < cost) continue;
		for (int k = 0; k < arr[idx].size(); k++) {
			int nextN = arr[idx][k].first;
			int nextCost = arr[idx][k].second;
			if (dp[nextN] > nextCost + cost) {
				dp[nextN] = nextCost + cost;
				pq.push({ dp[nextN],nextN });
			}
		}
	}

	cout << dp[N] << "\n";
	return 0;
}*/