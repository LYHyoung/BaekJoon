#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 50001
using namespace std;

int p[MAX], pp[MAX], d[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);

	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;		// pp : p의 변화량
		pp[v[i].first]++;
		pp[v[i].second + 1]--;
	}

	for (int i = 1; i < MAX; i++) {				// p : 테이프 면적
		p[i] = p[i - 1] + pp[i];
		d[i] = d[i - 1] + p[i];
	}

	int ans = 0, idx = -1;
	for (int i = 7 * n; i < MAX; i++) {
		if (ans < d[i] - d[i - 7 * n]) {
			ans = d[i] - d[i - 7 * n];
			idx = i - 7 * n + 1;
		}
	}

	int res = 0;
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			if (v[i].second >= idx + 7 * j && v[i].first <= idx + 7 * (j + 1) - 1)
				res++;

	cout << res << "\n";
	return 0;
}