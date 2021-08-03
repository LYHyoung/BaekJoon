#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int N; cin >> N;
	vector<ll> v;
	while (N--) {
		ll a; cin >> a;
		v.push_back(a);
	}
	ll b, c; cin >> b >> c;
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		v[i] -= b; ans++;
		if (v[i] > 0) {
			ans += v[i] / c;
			if (v[i] % c > 0) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}