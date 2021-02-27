#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int Tc; cin >> Tc;

	while (Tc--) {
		cin >> N >> K;
		int time[MAX];
		int build[MAX] = { 0 };
		vector<int> v[MAX];
		
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}
		
		for (int i = 0; i < K; i++) {
			int s, e; cin >> s >> e;
			v[s].push_back(e);
			build[e]++;
		}

		int D; cin >> D;

		int result[MAX] = { 0 };
		queue<int> q;
		for (int i = 1; i <= N; i++)			// input index that don't have starting data
			if (!build[i]) q.push(i);

		while (build[D] > 0) {
			int cur = q.front();
			q.pop();

			for (int next : v[cur]) {
				result[next] = max(result[next], result[cur] + time[cur]);
				if (--build[next] == 0) q.push(next);
			}
		}

		cout << result[D] + time[D] << '\n';
	}

	return 0;
}
