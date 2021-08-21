#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

ll n, m, k;
vector<pair<ll, ll>> vc;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	ll sum = 0;
	for (int i = 0; i < k; i++) {
		ll v, c; cin >> v >> c;
		vc.push_back({ c,v });
	}
	sort(vc.begin(), vc.end());
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) {
		pq.push(-vc[i].second);
		sum += vc[i].second;
		if (pq.size() > n) {
			sum += pq.top();
			pq.pop();
		}
		if (pq.size() == n && sum >= m) {
			cout << vc[i].first << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}
