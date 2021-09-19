#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int k, n;
vector<ll> v;
bool check(ll mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++)
		cnt += v[i] / mid;
	if (cnt >= n)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> n;
	ll high = 0;
	ll low = 1;
	ll result = 0;
	for (int i = 0; i < k; i++) {
		ll t; cin >> t;
		v.push_back(t);
		high = max(high, v[i]);
	}
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(mid)) {
			if (result < mid)
				result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result << '\n';
	return 0;
}