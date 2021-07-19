#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
	int T; cin >> T;

	while (T--) {
		ll x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ll dx = x1 - x2;
		ll dy = y1 - y2;

		if (r1 > r2) swap(r1, r2);
		
		ll add = r2 + r1;
		add = add * add;

		ll sub = r2 - r1;
		sub = sub * sub;
		
		ll d = dx * dx + dy * dy;

		if (d < add && d > sub)
			cout << 2;
		else if (d == add || (d == sub && d != 0))
			cout << 1;
		else if (d < sub || d > add)
			cout << 0;
		else if (d == 0) {
			if (r1 == r2)
				cout << -1;
			else
				cout << 0;
		}
		cout << '\n';
	}
	return 0;
}