#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	int ans = 1;
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for (int i = 1; i < v.size(); i++) {
		while (!pq.empty() && pq.top() <= v[i].first)
			pq.pop();
		pq.push(v[i].second);
		ans = max(ans, (int)pq.size());
	}
	cout << ans << '\n';
	return 0;
}