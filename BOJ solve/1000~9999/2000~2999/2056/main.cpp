#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

queue<int> q;
int N;
int t[MAX], cost[MAX], ind[MAX];
vector<int> prv[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	int c, n, p;
	for (int i = 1; i <= N; i++) {
		cin >> c >> n;
		t[i] = cost[i] = c;
		for (int j = 0; j < n; j++) {
			cin >> p;
			prv[p].push_back(i);
			ind[i]++;
		}
	}

	for (int i = 1; i <= N; i++)
		if (ind[i] == 0)
			q.push(i);

	int ans = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < prv[cur].size(); i++) {
			int nextcur = prv[cur][i];
			if (cost[nextcur] < t[nextcur] + cost[cur])
				cost[nextcur] = t[nextcur] + cost[cur];
			ind[nextcur]--;
			if (ind[nextcur] == 0)
				q.push(nextcur);
		}
	}

	for (int i = 1; i <= N; i++)
		if (ans < cost[i])
			ans = cost[i];

	cout << ans << '\n';

	return 0;
}