/*
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50+1
using namespace std;
int v[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> map;

	while (1) {
		int s, e; cin >> s >> e;
		if (s == -1 && e == -1) break;
		v[s][e] = 1;
		v[e][s] = 1;
	}

	int point = 0, pre = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += v[i][j];
		}
		if (point < sum) {
			point = sum;
		}
	}

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += v[i][j];
		}
		if (sum == point) {
			map.push_back(i);
		}
	}
	int s = map.size();
	cout << N - point << " " << s << '\n';
	for (int i = 0; i < s; i++) {
		cout << map[i] << " ";
	}
	return 0;
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> v(N, vector<int>(N, INF));
	vector<int> cost(N);
	while (true) {
		int x, y; cin >> x >> y;
		if (x == -1 && y == -1) break;
		v[x - 1][y - 1] = 1;
		v[y - 1][x - 1] = 1;
	}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (v[i][j] > v[i][k] + v[k][j])
					v[i][j] = v[i][k] + v[k][j];
	int r = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			cost[i] = max(cost[i], v[i][j]);
		}
		r = min(cost[i], r);
	}
	int c = 0;
	for (int i = 0; i < N; i++)
		if (r == cost[i]) c++;
	cout << r << " " << c << '\n';
	for (int i = 0; i < N; i++)
		if (r == cost[i]) cout << i + 1 << " ";
	return 0;
}