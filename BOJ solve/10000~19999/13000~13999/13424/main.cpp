#include <iostream>		// 13424
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 102
#define INF 987654321
typedef pair<int, int> PAIR;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++) {
		int N, M; cin >> N >> M;

		vector<PAIR> v[MAX];
		int dist[MAX];
		for (int i = 0; i < M; i++) {
			int a, b, c; cin >> a >> b >> c;
			
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		int K; cin >> K;
		int idx[MAX];
		for (int i = 0; i < K; i++) {
			cin >> idx[i];
		}

		vector<vector<int>> mini;		// 친구 한명씩의 dist를 저장해줍니다.
		for (int i = 0; i < K; i++) {
			priority_queue<PAIR, vector<PAIR>, greater<PAIR>> PQ;
			vector<int> dist(N + 1, INF);
			PQ.push({ 0,idx[i] });
			dist[idx[i]] = 0;

			while (!PQ.empty()) {
				int cur = PQ.top().first;
				int cv = PQ.top().second;
				PQ.pop();
				for (int i = 0; i < v[cv].size(); i++) {
					int id = v[cv][i].first;
					int leng = v[cv][i].second ;
					if (dist[id] > dist[cv] + leng) {
						dist[id] = dist[cv] + leng;
						PQ.push({ dist[id],id });
					}
				}
			}

			mini.push_back(dist);
		}
		for (int i = 1; i <= N; i++) {
			cout << i << " : "<< mini[0][i] << "   " << mini[1][i] << '\n';
		}
		int ans = INF; int ans_i = MAX;
		for (int i = N; i > 0; i--) {
			int s = 0;
			for (int j = 0; j < K; j++) s += mini[j][i];
			if (ans >= s) {
				ans = s; ans_i = i;
			}
		}
		cout << ans_i << '\n';
	}
	return 0;
}
