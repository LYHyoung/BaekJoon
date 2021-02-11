#define _CRT_SECURE_NO_WARNINGS
#include <iostream>			// 10715
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10001
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	const ll INF = 1ll << 60;
	ll C, sum = 0, ans = INF;
	cin >> N >> M >> C;

	vector<pair<int, ll>> v[MAX];		//vector<pair<int, ll>> v[N + 1];
	vector<ll> dist(N + 1);
	vector<bool> did(N + 1, 0);

	for (int i=0;i<M;i++) {
		int ai, bi;
		ll di;
		cin >> ai >> bi >> di;
		v[ai].push_back({ bi,di });
		v[bi].push_back({ ai,di });
		sum += di;
	}

	for (int i = 2; i <= N; i++) dist[i] = INF;

	priority_queue<pair<ll, int>> PQ;
	vector<pair<ll, int>> a;
	PQ.push({ 0,1 });
	
	while (!PQ.empty()) {
		int idx = PQ.top().second;
		ll cost = -PQ.top().first;
		PQ.pop();
		if (dist[idx] < cost) continue;
		a.push_back({ cost,idx });
		for (int i = 0; i < v[idx].size(); i++) {
			int nextidx = v[idx][i].first;
			int nextcost = v[idx][i].second;
			if (dist[nextidx] > cost + nextcost) {
				dist[nextidx] = nextcost + cost;
				PQ.push({ -dist[nextidx],nextidx });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int j = i;
		while (j < N && a[i].first == a[j].first) {
			int u = a[j].second;
			did[u] = 1;
			for (auto k : v[u]) {
				int ver = k.first;
				if (did[ver]) sum -= k.second;
			}
			j++;
		}
		ans = min(ans, C * a[i].first + sum);
		i = j - 1;
	}
	printf("%lld", ans);
	return 0;
}